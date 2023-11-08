/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 12:01:17 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#define MOVESPEED 0.08f
#define MARGIN	0.1f

void	move_up(t_data *this)
{
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x + this->camera.dir_x * MARGIN)] != 1)
			this->player.pos_x += this->camera.dir_x * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y - this->camera.dir_y * MARGIN)]
		[(int)(this->player.pos_x)] != 1)
			this->player.pos_y -= this->camera.dir_y * MOVESPEED;
}

void	move_left(t_data *this)
{
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x - this->camera.dir_y * MARGIN)] != 1)
		this->player.pos_x -= this->camera.dir_y * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y - this->camera.dir_x * MARGIN)]
		[(int)(this->player.pos_x)] != 1)
			this->player.pos_y -= this->camera.dir_x * MOVESPEED;
}

void	move_down(t_data *this)
{
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x - this->camera.dir_x * MARGIN)] != 1)
		this->player.pos_x -= this->camera.dir_x * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y + this->camera.dir_y * MARGIN)]
		[(int)(this->player.pos_x)] != 1)
		this->player.pos_y += this->camera.dir_y * MOVESPEED;
}

void	move_right(t_data *this)
{
	if (this->map_info.level[(int)(this->player.pos_y)]
		[(int)(this->player.pos_x + this->camera.dir_y * MARGIN)] != 1)
		this->player.pos_x += this->camera.dir_y * MOVESPEED;
	if (this->map_info.level[(int)(this->player.pos_y + this->camera.dir_x * MARGIN)]
		[(int)(this->player.pos_x)] != 1)
		this->player.pos_y += this->camera.dir_x * MOVESPEED;
}