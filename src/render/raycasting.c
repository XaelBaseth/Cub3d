/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:01:06 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/11 15:25:16 by cpothin          ###   ########.fr       */
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
		ray->sidedist_x = (ray->map_x + 1.0 - data->player.pos_x)
			* ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (data->player.pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - data->player.pos_y)
			* ray->deltadist_y;
	}
}

void	find_dist_wall(t_data *data, t_ray *ray)
{
	while (1)
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
			break ;
	}
}

void	find_wall_height(t_ray *ray)
{
	if (!ray->side)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	find_wall_pixel(t_data *data, t_ray *ray, int x)
{
	if (!ray->side)
		ray->wall_x = (int)data->player.pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = (int)data->player.pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)IMG_SIZE);
	if (!ray->side && ray->dir_x > 0)
		ray->tex_x = IMG_SIZE - ray->tex_x;
	if (ray->side && ray->dir_y < 0)
		ray->tex_x = IMG_SIZE - ray->tex_x;
	ray->step = 1.0 * IMG_SIZE / ray->line_height;
	ray->tex_pos = (ray->draw_start - (WIN_HEIGHT / 2) + ray->line_height / 2)
		* ray->step;
}
