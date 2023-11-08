/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:39 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/08 08:02:46 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_args(t_data *data, char *lines[])
{
	if (lines[0][0] == 'N' && lines[0][1] == 'O' && lines[0][2] == ' ')
		if (save_img(data, &data->texinfo.north, lines[0]) == 0)
			return (0);
	if (lines[1][0] == 'S' && lines[1][1] == 'O' && lines[1][2] == ' ')
		if (save_img(data, &data->texinfo.south, lines[1]) == 0)
			return (0);
	if (lines[2][0] == 'W' && lines[2][1] == 'E' && lines[2][2] == ' ')
		if (save_img(data, &data->texinfo.east, lines[2]) == 0)
			return (0);
	if (lines[3][0] == 'E' && lines[3][1] == 'A' && lines[3][2] == ' ')
		if (save_img(data, &data->texinfo.west, lines[3]) == 0)
			return (0);
	if (lines[4][0] == 'F' && lines[5][1] == ' ')
		if (save_rgb(data, data->texinfo.floor_rgb, lines[4]) == 0)
			return (0);
	if (lines[5][0] == 'C' && lines[5][1] == ' ')
		if (save_rgb(data, data->texinfo.sky_rgb, lines[5]) == 0)
			return (0);
	return (1);
}

void	parse_map(t_data *data, char *args[])
{
	if (!check_args(data, args))
		return ;
	// data->cube_info.height = IMG_SIZE;
	// data->cube_info.width = IMG_SIZE;
	data->map_info.height = WIN_HEIGHT;
	data->map_info.width = WIN_WIDTH;
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
			if (data->map_info.level[y][x] == 'N'
			|| data->map_info.level[y][x] == 'W'
			|| data->map_info.level[y][x] == 'S'
			|| data->map_info.level[y][x] == 'E')
			{
				data->player.pos_x = x;
				data->player.pos_y = y;
				data->player.dir = data->map_info.level[y][x];
				break ;
			}
			x++;
		}
		y++;
	}
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
		exit_message("Error\n\tMap error\n", &fd);
	file_content = gc_alloc(sizeof(char) * (BUFFER + 1), "map_content");
	read_int = read(fd, file_content, BUFFER);
	if (read_int < 0)
		exit_message("Error\n\tInvalid file.\n", &fd);
	file_content[read_int] = 0;
	close(fd);
	level = extract_map(file_content);
	data->file_content = ft_split(file_content, '\n');
	data->map_info.level = ft_split(level, '\n');
	parse_map(data, data->file_content);
	save_player(data);
	init_player_pov(data);
	gc_free(file_content);
	gc_free(level);
}
