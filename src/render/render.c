#include "../../inc/cub3d.h"

void	draw_vertical_line(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = -1;
	while (++y < ray->draw_start)
	{
		put_pixel_img(&data->img, x, y, create_tex_rgb(256,	data->texinfo.sky_rgb[0], data->texinfo.sky_rgb[1], data->texinfo.sky_rgb[2]));
	}
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (IMG_SIZE - 1);
		ray->tex_pos += ray->step;
		put_pixel_img(&data->img, x, y, get_color(data, ray));
		y += 1;
	}
	y = ray->draw_end;
	while (y < WIN_HEIGHT)
	{
		put_pixel_img(&data->img, x, y, create_tex_rgb(256,	data->texinfo.floor_rgb[0], data->texinfo.floor_rgb[1], data->texinfo.floor_rgb[2]));
		y += 1;
	}
}

void	render_frame(t_data *data)
{
	int		x;
	t_ray	ray;

	data->img = new_img(data->mlx);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(data, &ray, x);
		point_rays(data, &ray);
		find_dist_wall(data, &ray);
		find_wall_height(&ray);
		find_wall_pixel(data, &ray);
		draw_vertical_line(data, &ray, x);
		x += 1;
	}
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}