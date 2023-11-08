/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:56:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/08 11:04:07 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_vector2	max_map_size(t_data *data)
{
	t_vector2	vec;
	t_vector2	pos;
	int			cur_max;
	int			max;

	pos.y = 0;
	max = 0;
	vec.x = 0;
	while (data->map_info.level[pos.y])
	{
		pos.x = 0;
		cur_max = 0;
		while (data->map_info.level[pos.y][pos.x])
		{
			cur_max++;
			pos.x++;
		}
		if (cur_max > vec.x)
			vec.x = cur_max;
		pos.y++;
	}
	vec.y = pos.y;
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
