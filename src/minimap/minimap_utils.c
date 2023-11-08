/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:56:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/08 08:47:14 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_vector2	max_map_size(t_data *data)
{
	t_vector2	vec;
	int			cur_max;
	int			max;
	int			x;
	int			y;

	y = 0;
	max = 0;
	vec.x = 0;
	while (data->map_info.level[y])
	{
		x = 0;
		cur_max = 0;
		while (data->map_info.level[y][x])
		{
			cur_max++;
			x++;
		}
		if (cur_max > vec.x)
			vec.x = cur_max;
		y++;
	}
	vec.y = y;
	return (vec);
}

void	zoom_in(t_data *data)
{
	if (data->minimap.zoom < 20)
	{
		data->minimap.zoom += 2;
		create_minimap(data);
	}
}

void	zoom_out(t_data *data)
{
	if (data->minimap.zoom > 4)
	{
		data->minimap.zoom -= 2;
		create_minimap(data);
	}
}
