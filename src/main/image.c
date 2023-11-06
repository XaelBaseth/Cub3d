/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:17:15 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/06 09:22:14 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned int	extract_pixel_from_image(t_img *img, int point_x, int point_y)
{
	return (*(unsigned int *)(img->addr + (point_x * img->size_line)
		+ (point_x * img->bpp / 8)));
}

unsigned int	get_color(t_data *data, t_ray *ray)
{
	if (!ray->side)
	{
		if (data->player.pos_x > ray->map_x)
			return (extract_pixel_from_image(&data->texinfo.west,
					ray->tex_x, ray->tex_y));
		return (extract_pixel_from_image(&data->texinfo.east,
				ray->tex_x, ray->tex_y));
	}
	if (data->player.pos_y > ray->map_y)
		return (extract_pixel_from_image(&data->texinfo.north,
				ray->tex_x, ray->tex_y));
	return (extract_pixel_from_image(&data->texinfo.south,
			ray->tex_x, ray->tex_y));
}

t_img	new_img(void *mlx)
{
	t_img	new_img;

	new_img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bpp,
			&new_img.size_line, &new_img.endian);
	return (new_img);
}

void	put_pixel_img(t_img *img, int x, int y, unsigned int color)
{
	char	*dest;

	//printf("\nx : %d", x);
	//printf("\ny : %d", y);
	//printf("\ncolor : %d", color);
	dest = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

int	create_tex_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
