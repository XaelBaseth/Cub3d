/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:00 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/10 18:28:54 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_side(t_data *this, int i)
{
	char	c;

	if (!BONUS)
	{
		this->player.pos_x += this->camera.dir_y * MOVESPEED * -i;
		this->player.pos_y += this->camera.dir_x * MOVESPEED * i;
		return ;
	}
	c = this->map_info.level[(int)(this->player.pos_y)]
	[(int)(this->player.pos_x + this->camera.dir_y * MARGIN * -i)];
	if (c != '1' && c != 'D')
		this->player.pos_x += this->camera.dir_y * MOVESPEED * -i;
	c = this->map_info.level
	[(int)(this->player.pos_y + this->camera.dir_x * MARGIN * i)]
	[(int)(this->player.pos_x)];
	if (c != '1' && c != 'D')
		this->player.pos_y += this->camera.dir_x * MOVESPEED * i;
}

void	move_forward(t_data *this, int i)
{
	char	c;

	if (!BONUS)
	{
		this->player.pos_x += this->camera.dir_x * MOVESPEED * i;
		this->player.pos_y += this->camera.dir_y * MOVESPEED * i;
		return ;
	}
	c = this->map_info.level[(int)(this->player.pos_y)]
	[(int)(this->player.pos_x + this->camera.dir_x * MARGIN * i)];
	if (c != '1' && c != 'D')
		this->player.pos_x += this->camera.dir_x * MOVESPEED * i;
	c = this->map_info.level
	[(int)(this->player.pos_y + this->camera.dir_y * MARGIN * i)]
	[(int)(this->player.pos_x)];
	if (c != '1' && c != 'D')
		this->player.pos_y += this->camera.dir_y * MOVESPEED * i;
}

void	move_player(t_data *data)
{
	if (data->player.movement.y != 0)
		move_forward(data, -data->player.movement.y);
	if (data->player.movement.x != 0)
		move_side(data, data->player.movement.x);
}
