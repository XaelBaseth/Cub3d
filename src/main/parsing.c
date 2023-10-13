/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:39 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/13 17:05:43 by cpothin          ###   ########.fr       */
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
	nbrs = ft_split(arg[1], ',');
	if (!check_nbr(nbrs[0]) || !check_nbr(nbrs[1]) || !check_nbr(nbrs[2]))
		return (0);
	var->r = ft_atoi(nbrs[0]);
	var->g = ft_atoi(nbrs[1]);
	var->b = ft_atoi(nbrs[2]);
	return (1);
}

static int	save_img(t_data *data, void *img, char *arg)
{
	int	*size;
	char	**args;

	args = ft_split(arg, ' ');
	size = IMG_SIZE;
	if (!args[1])
		return (0);
	img = mlx_xpm_file_to_image(data->mlx,
			args[1], &size, &size);
	if (!img)
	{
		ft_printf("Error\n\t%s not found", args[1]);
		return (0);
	}
	return (1);
}

int		check_args(t_data *data, char *args[])
{
	if (args[0][0] == 'N' && args[0][1] == 'O' && args[0][2] == ' ')
		if (save_img(data, data->cube_info.texture_north, args[0]) == 0)
			return (0);
	if (args[1][0] == 'S' && args[1][1] == 'O' && args[1][2] == ' ')
		if (save_img(data, data->cube_info.texture_south, args[1]) == 0)
			return (0);
	if (args[2][0] == 'W' && args[2][1] == 'E' && args[2][2] == ' ')
		if (save_img(data, data->cube_info.texture_west, args[2]) == 0)
			return (0);
	if (args[3][0] == 'E' && args[3][1] == 'A' && args[3][2] == ' ')
		if (save_img(data, data->cube_info.texture_east, args[3]) == 0)
			return (0);
	if (args[5][0] == 'F' && args[5][1] == ' ')
		if (save_color(data, &data->map_info.floor_color, args[5]) == 0)
			return (0);
	if (args[6][0] == 'C' && args[5][1] == ' ')
		if (save_color(data, &data->map_info.ceiling_color, args[6]) == 0)
			return (0);
	return (1);
}

void	parse_map(t_data *data, char *args[])
{
	if (!check_args(data, args))
		return ;

	data->cube_info.height = IMG_SIZE;
	data->cube_info.width = IMG_SIZE;
}

void	read_file(t_data *data, char *map_name)
{
	int	fd;
	int	read_int;

	fd = open(map_name, O_RDONLY);
	read_int = read(fd, data->map_str, BUFFER);
	if (read_int < 0)
	{
		ft_printf("Error\n\tInvalide file.");
		return ;
	}
	data->map_info.level = ft_split(data->map_str, '\n');
}