/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:18:27 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/10 10:10:34 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	north_pov(t_data *data)
{
	data->camera.plane_x = 0.66;
	data->camera.plane_y = 0;
	data->camera.dir_x = 0.0f;
	data->camera.dir_y = -1.0f;
}

static void	south_pov(t_data *data)
{
	data->camera.plane_x = -0.66;
	data->camera.plane_y = 0;
	data->camera.dir_x = 0.0f;
	data->camera.dir_y = 1.0f;
}

static void	east_pov(t_data *data)
{
	data->camera.plane_x = 0;
	data->camera.plane_y = -0.66;
	data->camera.dir_x = 1.0f;
	data->camera.dir_y = 0.0f;
}

static void	west_pov(t_data *data)
{
	data->camera.plane_x = 0;
	data->camera.plane_y = 0.66;
	data->camera.dir_x = -1.0f;
	data->camera.dir_y = 0.0f;
}

void	init_player_pov(t_data *data)
{
	if (data->player.dir == 'N')
		north_pov(data);
	else if (data->player.dir == 'S')
		south_pov(data);
	else if (data->player.dir == 'E')
		east_pov(data);
	else if (data->player.dir == 'W')
		west_pov(data);
}
