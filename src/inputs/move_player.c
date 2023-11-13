/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/13 08:21:45 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_side(t_data *data, int i)
{
	char	c;

	if (!BONUS)
	{
		data->player.pos_x += data->camera.dir_y * MOVESPEED * -i;
		data->player.pos_y += data->camera.dir_x * MOVESPEED * i;
		return ;
	}
	c = data->map_info.level[(int)(data->player.pos_y)]
	[(int)(data->player.pos_x + data->camera.dir_y * MARGIN * -i)];
	if (c == '0')
		data->player.pos_x += data->camera.dir_y * MOVESPEED * -i;
	c = data->map_info.level
	[(int)(data->player.pos_y + data->camera.dir_x * MARGIN * i)]
	[(int)(data->player.pos_x)];
	if (c == '0')
		data->player.pos_y += data->camera.dir_x * MOVESPEED * i;
}

void	move_forward(t_data *data, int i)
{
	char	c;

	if (!BONUS)
	{
		data->player.pos_x += data->camera.dir_x * MOVESPEED * i;
		data->player.pos_y += data->camera.dir_y * MOVESPEED * i;
		return ;
	}
	c = data->map_info.level[(int)(data->player.pos_y)]
	[(int)(data->player.pos_x + data->camera.dir_x * MARGIN * i)];
	if (c != '1' && c != 'D' && c)
		data->player.pos_x += data->camera.dir_x * MOVESPEED * i;
	c = data->map_info.level
	[(int)(data->player.pos_y + data->camera.dir_y * MARGIN * i)]
	[(int)(data->player.pos_x)];
	if (c != '1' && c != 'D' && c)
		data->player.pos_y += data->camera.dir_y * MOVESPEED * i;
}

int	move_player(t_data *data)
{
	if (data->player.movement.y != 0)
		move_forward(data, -data->player.movement.y);
	if (data->player.movement.x != 0)
		move_side(data, data->player.movement.x);
}
