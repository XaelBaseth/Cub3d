#include "../../inc/cub3d.h"


static void	set_image_pixel(t_block *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

static void set_frame_image_pixel(t_data *data, t_block *image, int x, int y)
{
	//ft_printf("\nset_frame_image_pixel\nx->%d\ny->%d\ndata->textures_pixel[y][x]->%d\n", x, y, data->textures_pixel[y][x]);
	if (data->textures_pixel[y][x] > 0)
		set_image_pixel(image, x, y, data->textures_pixel[y][x]);
	else if (y < WIN_HEIGHT / 2)
		set_image_pixel(image, x, y, data->cube_info.hex_ceiling);
	else if (y < WIN_HEIGHT -1)
		set_image_pixel(image, x, y, data->cube_info.hex_floor);
}

static void	render_frame(t_data *data)
{
	t_block	image;
	int		x;
	int		y;

	image.image = NULL;
	init_img(data, &image, WIN_WIDTH, WIN_HEIGHT);
	y = 0;
	while (y < WIN_WIDTH)
	{
		x = 0;
		while (x < WIN_HEIGHT)
		{
			//ft_printf("\nrender_frame_params:\nx->%d\ny->%d", x, y);
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.image, 0, 0);
	mlx_destroy_image(data->mlx, image.image);
}

static void	render_raycast(t_data *data)
{
	init_texture_pixel(data);
	init_ray(&data->ray);
	raycasting(&data->player, data);
	render_frame(data);
}

void	render_images(t_data *data)
{
	render_raycast(data);
}
