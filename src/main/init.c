/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:14:27 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/02 15:00:28 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_img	init_img(void)
{
	printf("\n\n\nHello");
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
	
	//printf("camera_x: %f\n", ray->camera_x);
    //printf("dir_x: %f\n", ray->dir_x);
	//printf("camera.dir_x: %f\n", data->camera.dir_x);
	//printf("camera.plane_x: %f\n", data->camera.plane_x);
    //printf("dir_y: %f\n", ray->dir_y);
	//printf("camera.dir_y: %f\n", data->camera.dir_y);
	//printf("camera_plane_y : %f\n", data->camera.plane_y);	
    //printf("map_x: %d\n", ray->map_x);
	//printf("player.pos_x : %f\n", data->player.pos_x);
    //printf("map_y: %d\n", ray->map_y);
	//printf("player.pos_y: %f\n", data->player.pos_y);
    //printf("deltadist_x: %f\n", ray->deltadist_x);
    //printf("deltadist_y: %f\n", ray->deltadist_y);
}
