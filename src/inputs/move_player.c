/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/09 09:52:24 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->camera.dir_x * MOVESPEED;
	new_y = data->player.pos_y + data->camera.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->camera.dir_x * MOVESPEED;
	new_y = data->player.pos_y - data->camera.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->camera.dir_y * MOVESPEED;
	new_y = data->player.pos_y - data->camera.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->camera.dir_y * MOVESPEED;
	new_y = data->player.pos_y + data->camera.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == -1)
		moved += move_forward(data);
	if (data->player.move_y == 1)
		moved += move_backward(data);
	if (data->player.move_x == 1)
		moved += move_left(data);
	if (data->player.move_x == -1)
		moved += move_right(data);
	return (moved);
}