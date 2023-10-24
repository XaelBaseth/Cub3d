/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:39 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/24 11:41:30 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_nbr(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

static int	save_color(t_data *data, t_color *var, char *arg)
{
	char	**args;
	char	**nbrs;

	args = ft_split(arg, ' ');
	if (!args[1])
		return (0);
	nbrs = ft_split(args[1], ',');
	if (!check_nbr(nbrs[0]) || !check_nbr(nbrs[1]) || !check_nbr(nbrs[2]))
		return (0);
	var->r = ft_atoi(nbrs[0]);
	var->g = ft_atoi(nbrs[1]);
	var->b = ft_atoi(nbrs[2]);
	return (1);
}

static int	save_img(t_data *data, void **img, char *arg)
{
	int		size;
	char	**args;

	args = ft_split(arg, ' ');
	size = IMG_SIZE;
	if (!args[1])
		return (0);
	if (access(args[1], F_OK) == -1)
	{
		ft_printf("Error:\n\t%s doesn't exist\n", args[1]);
		return (0);
	}
	printf("\nsave_img:\nchar %s\nsize: %d\n", args[1], size);
	*img = mlx_xpm_file_to_image(data->mlx, args[1], &size, &size);
	return (1);
}

static int		check_args(t_data *data, char *args[])
{
	if (args[0][0] == 'N' && args[0][1] == 'O' && args[0][2] == ' ')
		if (save_img(data, &data->cube_info.texture_north, args[0]) == 0)
			return (0);
	if (args[1][0] == 'S' && args[1][1] == 'O' && args[1][2] == ' ')
		if (save_img(data, &data->cube_info.texture_south, args[1]) == 0)
			return (0);
	if (args[2][0] == 'W' && args[2][1] == 'E' && args[2][2] == ' ')
		if (save_img(data, &data->cube_info.texture_west, args[2]) == 0)
			return (0);
	if (args[3][0] == 'E' && args[3][1] == 'A' && args[3][2] == ' ')
		if (save_img(data, &data->cube_info.texture_east, args[3]) == 0)
			return (0);
	if (args[4][0] == 'F' && args[5][1] == ' ')
		if (save_color(data, &data->map_info.floor_color, args[4]) == 0)
			return (0);
	if (args[5][0] == 'C' && args[5][1] == ' ')
		if (save_color(data, &data->map_info.ceiling_color, args[5]) == 0)
			return (0);
	printf("\ncheckargs: data->cube_info.texture_north: %p\n", data->cube_info.texture_north);
	return (1);
}

void	parse_map(t_data *data, char *args[])
{
	if (!check_args(data, args))
		return ;

	data->cube_info.height = IMG_SIZE;
	data->cube_info.width = IMG_SIZE;
}

void	save_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_info.level[y])
	{
		x = 0;
		while (data->map_info.level[y][x])
		{
			if (data->map_info.level[y][x] == 'N' || data->map_info.level[y][x] == 'W'
			|| data->map_info.level[y][x] == 'S' || data->map_info.level[y][x] == 'E')
			{
				data->player.dir = data->map_info.level[y][x];
				break;
			}
			x++;
		}
		y++;
	}
}

char	*extract_map(char *map)
{
	int		i;
	int		j;
	char	*level;

	level = gc_alloc(sizeof(char) * BUFFER, "level");
	i = 0;
	j = 0;
	while (i < 8)
	{
		while (map[j] && map[j] != '\n')
			j++;
		i++;
		j++;
	}
	i = 0;
	while (map[j])
		level[i++] = map[j++];
	level[i] = 0;
	return (level);
}

void	read_file_map(t_data *data, char *map_name)
{
	int		fd;
	int		read_int;
	char	*full_map_path;
	char	*file_content;
	char	*level;

	full_map_path = ft_strjoin(MAP_PATH, map_name);
	fd = open(full_map_path, O_RDONLY);
	gc_free(full_map_path);
	if (fd == -1)
	{
		ft_printf("Error\n\tMap error  %d\n", fd);
		return ;
	}
	file_content = gc_alloc(sizeof(char) * (BUFFER + 1), "map_content");
	read_int = read(fd, file_content, BUFFER);
	if (read_int < 0)
	{
		ft_printf("Error\n\tInvalid file.\n");
		close(fd);
		return ;
	}
	file_content[read_int] = 0;
	close(fd);
	level = extract_map(file_content);
	data->file_content = ft_split(file_content, '\n');
	data->map_info.level = ft_split(level, '\n');
	parse_map(data, data->file_content);
	save_player(data);
	gc_free(file_content);
	gc_free(level);
}
