/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/10 08:37:47 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	move_forward(t_data *data)
{
	if (!BONUS)
	{
		this->player.pos_x += this->camera.dir_x * MOVESPEED;
		this->player.pos_y -= this->camera.dir_y * MOVESPEED;
		return ;
	}
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x + this->camera.dir_x * MARGIN)] != '1')
			this->player.pos_x += this->camera.dir_x * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y - this->camera.dir_y * MARGIN)]
		[(int)(this->player.pos_x)] != '1')
			this->player.pos_y -= this->camera.dir_y * MOVESPEED;
}

static int	move_backward(t_data *data)
{
	if (!BONUS)
	{
		this->player.pos_x -= this->camera.dir_y * MOVESPEED;
		this->player.pos_y -= this->camera.dir_x * MOVESPEED;
		return ;
	}
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x - this->camera.dir_y * MARGIN)] != '1')
			this->player.pos_x -= this->camera.dir_y * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y - this->camera.dir_x * MARGIN)]
		[(int)(this->player.pos_x)] != '1')
			this->player.pos_y -= this->camera.dir_x * MOVESPEED;
}

void	move_down(t_data *this)
{
	if (!BONUS)
	{
		this->player.pos_x -= this->camera.dir_x * MOVESPEED;
		this->player.pos_y += this->camera.dir_y * MOVESPEED;
		return ;
	}
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x - this->camera.dir_x * MARGIN)] != '1')
		this->player.pos_x -= this->camera.dir_x * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y + this->camera.dir_y * MARGIN)]
		[(int)(this->player.pos_x)] != '1')
		this->player.pos_y += this->camera.dir_y * MOVESPEED;
}

void	move_right(t_data *this)
{
	if (!BONUS)
	{
		this->player.pos_x += this->camera.dir_y * MOVESPEED;
		this->player.pos_y += this->camera.dir_x * MOVESPEED;
		return ;
	}
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x + this->camera.dir_y * MARGIN)] != '1')
		this->player.pos_x += this->camera.dir_y * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y + this->camera.dir_x * MARGIN)]
		[(int)(this->player.pos_x)] != '1')
		this->player.pos_y += this->camera.dir_x * MOVESPEED;
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