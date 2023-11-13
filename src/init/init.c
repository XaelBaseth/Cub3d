/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:11:28 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/13 10:30:04 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_img	init_img(void)
{
	t_img	img;

	img.img = NULL;
	img.addr = NULL;
	img.bpp = 0;
	img.size_line = 0;
	img.endian = 0;
}

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = data->camera.dir_x + data->camera.plane_x * ray->camera_x;
	ray->dir_y = data->camera.dir_y + data->camera.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

void	init_sizes(t_data *data)
{
	data->sizes.button_x = B_SIZE_W;
	data->sizes.button_y = B_SIZE_H;
	data->sizes.win_x = WIN_WIDTH;
	data->sizes.win_y = WIN_HEIGHT;
	data->sizes.title_x = 351;
	data->sizes.title_y = 100;
	data->sizes.credit_x = 190;
	data->sizes.credit_y = 25;
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	data->mouse_position.x = 0;
	data->mouse_position.y = 0;
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_position.x,
		&data->mouse_position.y);
}
