/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:47:40 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/14 10:18:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_size_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
		i++;
	return (i);
}

bool	is_player(t_data *data, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

int	get_map_height(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_info.level[i])
		i++;
	return (i);
}

void	check_map_borders(t_data *data, int x, int y)
{
	if (!data->map_info.map_is_valid || !data->map_info.tmplevel[y]
		|| !data->map_info.tmplevel[y][x]
		|| data->map_info.tmplevel[y][x] == ' ')
	{
		data->map_info.map_is_valid = 0;
		return ;
	}
	if (data->map_info.tmplevel[y][x] == '1')
		return ;
	data->map_info.tmplevel[y][x] = '1';
	check_map_borders(data, x + 1, y);
	check_map_borders(data, x - 1, y);
	check_map_borders(data, x, y + 1);
	check_map_borders(data, x, y - 1);
}

void	check_borders(t_data *data, char *level)
{
	int	x;
	int	y;

	data->map_info.tmplevel = ft_split(level, '\n');
	data->map_info.map_is_valid = 1;
	y = 0;
	while (data->map_info.tmplevel[y])
	{
		x = 0;
		while (data->map_info.tmplevel[y][x])
		{
			if (data->map_info.tmplevel[y][x] == '0'
				|| data->map_info.tmplevel[y][x] == 'D'
				|| is_player(data, data->map_info.tmplevel[y][x]))
				check_map_borders(data, x, y);
			x++;
		}
		y++;
	}
	if (data->map_info.map_is_valid == 0)
	{
		ft_printf("Error:\n\tThe map is not entirely surrounded by walls\n");
		exit_game(data);
	}
}
