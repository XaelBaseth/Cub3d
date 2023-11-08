/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:46:49 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 10:17:47 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

void	init_mini_tmp(t_data *data, t_minimap_tmp *mini_tmp)
{
	mini_tmp->shift = (int)(MINIMAP_SIZE / (double)data->minimap.zoom
			/ 2.0 + 0.999999);
	mini_tmp->pos.y = (int)data->player.pos_y - mini_tmp->shift;
	mini_tmp->offset.y = 0;
	mini_tmp->big_shift = (mini_tmp->shift * data->minimap.zoom * 2
			- MINIMAP_SIZE) / 2 + data->minimap.zoom / 2;
}
