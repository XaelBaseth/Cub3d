/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:54:51 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/07 17:02:14 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	rotate_left_right(t_data *data, double rotspeed)
{
	t_camera	*cam;
	double		tmp_x;

	cam = &data->camera;
	tmp_x = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(rotspeed) - cam->dir_y * sin(rotspeed);
	cam->dir_y = tmp_x * sin(rotspeed) + cam->dir_y * cos(rotspeed);
	tmp_x = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(rotspeed) - cam->plane_y * sin(rotspeed);
	cam->plane_y = tmp_x * sin(rotspeed) + cam->plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_data *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = 0.02 * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}