#include "../../inc/cub3d.h"

void	init_texture_pixel(t_data *data)
{
	int i;

	data->textures_pixel = ft_calloc(WIN_HEIGHT + 1, sizeof
		* data->textures_pixel);
	if (!data->textures_pixel)
		panic(data, "Unable to load the texture images.");
	i = 0;	
	while (i < WIN_HEIGHT)
	{
		data->textures_pixel[i] = ft_calloc(WIN_WIDTH + 1,
			sizeof * data->textures_pixel);
		if (!data->textures_pixel[i])
			panic(data, "Unable to load the texture images 2.");
		i++;	
	}
}

/*
	This function get the index of the wall side hit by the redirection.
	@param `*data` - environment of the game.
	@param `*ray` - raycasting.
*/
void	texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->cube_info.index = WEST;
		else
			data->cube_info.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->cube_info.index = SOUTH;
		else
			data->cube_info.index = NORTH;
	}
}

void	update_texture_pixel(t_data *data, t_block *block, t_ray *ray, int x)
{
	int	y;
	int	color;

	texture_index(data, ray);
	block->x = (int)(ray->wall_x * block->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		block->x = block->size - block->x - 1;
	block->step = 1.0 * block->size / ray->line_height;
	block->pos = (ray->draw_start - WIN_HEIGHT / 2 
		+ ray->line_height / 2) * block->step;
	y = ray->draw_start;
	//printf("\nupdate_texture_pixel_param:\nray->draw_start:%d\nray->draw_end->%d\ny->%d\nx->%d\n", ray->draw_start, ray->draw_end, y, x);
	while (y < ray->draw_end)
	{
		ft_printf("Hello");
		block->y = (int)block->pos & (block->size - 1);
		block->pos += block->step;
		color = data->textures[block->index][block->size * block->y + block->x];
		ft_printf("\nupdate_texture_pixel_color->%d\n", color);
		if (block->index == NORTH || block->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->textures_pixel[y][x] = color;
		y++;
	}
}