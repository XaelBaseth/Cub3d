/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:56:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/06 10:16:33 by cpothin          ###   ########.fr       */
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

void	init_minimap(t_data *data)
{
	data->minimap.lwr_rt.x = WIN_WIDTH - 10;
	data->minimap.lwr_rt.y = WIN_HEIGHT - 10;
	data->minimap.up_rt.x = WIN_WIDTH - 10;
	data->minimap.lwr_lft.y = WIN_HEIGHT - 10;
	data->minimap.up_left.x = WIN_WIDTH - 10 - MINIMAP_SIZE;
	data->minimap.up_left.y = WIN_HEIGHT - 10 - MINIMAP_SIZE;
	data->minimap.up_rt.y = WIN_HEIGHT - 10 - MINIMAP_SIZE;
	data->minimap.lwr_lft.x = WIN_WIDTH - 10 - MINIMAP_SIZE;
	data->minimap.center.x = (data->minimap.up_left.x
			+ data->minimap.up_rt.x) / 2;
	data->minimap.center.y = (data->minimap.up_left.y
			+ data->minimap.lwr_lft.y) / 2;
	data->minimap.zoom = 8;
	data->minimap.map_size = max_map_size(data);
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

void	init_mini_tmp(t_data *data, t_minimap_tmp *mini_tmp)
{
	mini_tmp->shift = (int)(MINIMAP_SIZE / (double)data->minimap.zoom
			/ 2.0 + 0.999999);
	mini_tmp->pos.y = (int)data->player.pos_y - mini_tmp->shift;
	mini_tmp->offset.y = 0;
	mini_tmp->big_shift = (mini_tmp->shift * data->minimap.zoom * 2
			- MINIMAP_SIZE) / 2 + data->minimap.zoom / 2;
}
