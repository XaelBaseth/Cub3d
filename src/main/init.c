/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:14:27 by acharlot          #+#    #+#             */
/*   Updated: 2023/10/24 11:15:19 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_img_clean(t_block *img)
{
	img->image = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_texture_img(t_data *data, t_block *image, char *path)
{
	init_img_clean(image);
	//ft_printf("\n path->%s \n size->%d\n", path, data->cube_info.size);
	image->image = mlx_xpm_file_to_image(data->mlx, path, &data->cube_info.size,
		&data->cube_info.size);
	ft_printf("init_text :\npath => %s\ndata->cube_info.size = %d\n", path, data->cube_info.size);
	if (image->image == NULL)
		panic(data, "init_text_img: Failed to load the images.");
	image->addr = (int *)mlx_get_data_addr(image->image, &image->pixel_bits,
		&image->size_line, &image->endian);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		panic(data, "init_mlx: Failed to initialize the minilibx.");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!data->win)
		panic(data, "init_mlx: Failed to initialize the minilibx window.");
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_img(t_data *data, t_block *image, int width, int height)
{
	init_img_clean(image);
	//ft_printf("\nVariable init_img :\n%d->width\n%d->height\n", width, height);
	image->image = mlx_new_image(data->mlx, width, height);
	if (image->image == NULL)
		panic(data, "init_img: Unable to load some images.");
	image->addr = (int *)mlx_get_data_addr(image->image,
		&image->pixel_bits, &image->size_line, &image->endian);
	return ;
}

static int	*xpm_to_image(t_data *data, char *path)
{
	t_block	tmp;
	int		*buffer;
	int		x;
	int		y;

	ft_printf("\nxpm_to_img:\npath=%s\n", path);
	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer * data->cube_info.size * data->cube_info.size);
	if (!buffer)
		panic(data, "xpm_to_image: Failed to allocate memory.");
	y = 0;
	while (y < data->cube_info.size)
	{
		x = 0;
		while (x < data->cube_info.size)
		{
			buffer[y * data->cube_info.size + x] = tmp.addr[y * data->cube_info.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.image);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		panic(data, "init_textures: Failed to allocate memory.");
	printf("\ninit_textures:\ntex_north: %s\n", (char *)data->cube_info.texture_north);
	data->textures[NORTH] = xpm_to_image(data, data->cube_info.texture_north);
	data->textures[SOUTH] = xpm_to_image(data, data->cube_info.texture_south);
	data->textures[EAST] = xpm_to_image(data, data->cube_info.texture_east);
	data->textures[WEST] = xpm_to_image(data, data->cube_info.texture_west);
}

void	init_cubeinfo(t_block *cube_info)
{
	cube_info->hex_ceiling = 0x0;
	cube_info->hex_floor = 0;
	cube_info->size = 128;
	cube_info->texture_south = "textures/SO.xpm";
	cube_info->texture_east = "textures/EA.xpm";
	cube_info->texture_west = "textures/WE.xpm";
}

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->pos_x = 0.0;
	player->pos_y = 0.0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->textures_pixel = NULL;
	data->textures = NULL;
	init_player(&data->player);
	init_cubeinfo(&data->cube_info);
	init_img_clean(&data->cube_info);
	init_player_direction(data);
}