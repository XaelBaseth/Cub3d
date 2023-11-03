/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:01:06 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/03 14:22:37 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	point_rays(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (data->player.pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0f - data->player.pos_x)
			* ray->deltadist_x;
	}
	if (ray->dir_y > 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0f - data->player.pos_y)
			* ray->deltadist_y;
	}
	//printf("\n\nray->sidedist_x : %f", ray->sidedist_x);
	//printf("\nplayer.pos_x : %f", data->player.pos_x);
	//printf("\nmap_x : %d", ray->map_x);
	//printf("\ndeltadist_x : %f\n", ray->deltadist_x);
	//printf("\n\nray->sidedist_y : %f", ray->sidedist_y);
	//printf("\nplayer.pos_y : %f", data->player.pos_y);
	//printf("\nmap_y : %d", ray->map_y);
	//printf("\ndeltadist_y : %f\n", ray->deltadist_y);
}

void	find_dist_wall(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->map_info.height - 0.25
			|| ray->map_x > data->map_info.width - 1.25)
			break ;
		else if (data->map_info.level[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
	//printf("map_y : %d\n", ray->map_y);
	//printf("map_x : %d\n", ray->map_x);
	//printf("map.info_height : %d\n", data->map_info.height);
	//printf("map_info.width : %d\n", data->map_info.width);
}

void	find_wall_height(t_ray *ray)
{
	if(!ray->side)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end= WIN_HEIGHT - 1;
	
	//printf("\nside : %d", ray->side);
	//printf("\nwall_dist: %f", ray->wall_dist);
	//printf("\nline_height: %d", ray->line_height);
	//printf("\nWIN_HEIGHT : %d", WIN_HEIGHT);
	//printf("\ndraw_start : %d", ray->draw_start);
	//printf("\ndraw_end : %d", ray->draw_end);
}

void	find_wall_pixel(t_data *data, t_ray *ray)
{
	if (!ray->side)
		ray->wall_x = (int)data->player.pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = (int)data->player.pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)128);
	if (!ray->side && ray->dir_x > 0)
		ray->tex_x = 128 - ray->tex_x - 1;
	if (ray->side && ray->dir_y < 0)
		ray->tex_x = 128 - ray->tex_x - 1;
	ray->step = 1.0 * 128 / ray->line_height;
	ray->tex_pos = (ray->draw_start - (WIN_HEIGHT / 2) + ray->line_height / 2)
		* ray->step;
}
