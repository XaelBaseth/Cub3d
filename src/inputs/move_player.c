/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/09 16:00:37 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_up(t_data *this)
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
	if (this->map_info.level
		[(int)(this->player.pos_y - this->camera.dir_y * MARGIN)]
		[(int)(this->player.pos_x)] != '1')
		this->player.pos_y -= this->camera.dir_y * MOVESPEED;
}

void	move_left(t_data *this)
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
	if (this->map_info.level
		[(int)(this->player.pos_y - this->camera.dir_x * MARGIN)]
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
	if (this->map_info.level
		[(int)(this->player.pos_y + this->camera.dir_y * MARGIN)]
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
	if (this->map_info.level
		[(int)(this->player.pos_y + this->camera.dir_x * MARGIN)]
		[(int)(this->player.pos_x)] != '1')
		this->player.pos_y += this->camera.dir_x * MOVESPEED;
}

void	move_player(t_data *data)
{
	if (data->player.movement.y == -1)
		move_up(data);
	else if (data->player.movement.y == 1)
		move_down(data);
	if (data->player.movement.x == -1)
		move_left(data);
	else if (data->player.movement.x == 1)
		move_right(data);
}
