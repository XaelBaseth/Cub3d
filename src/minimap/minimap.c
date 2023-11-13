/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:30:14 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/11 17:15:54 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_map_color(t_data *data, t_vector2 pos)
{
	char	c;

	if (pos.y < 0 || pos.x < 0
		|| pos.y > data->minimap.map_size.y
		|| pos.x > ft_strlen(data->map_info.level[pos.y])
		|| !data->map_info.level[pos.y] || !data->map_info.level[pos.y][pos.x])
		return (0x1C1C1C);
	c = data->map_info.level[pos.y][pos.x];
	if (c == '1')
		return (0x404050);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (0x888892);
	else if (c == 'D')
		return (0xBBBB99);
	return (0x1C1C1C);
}

void	fill_pixels(t_data *data, int size_line, int bpp,
	t_minimap_tmp *mini_tmp)
{
	t_vector2	pos;
	t_vector2	off;
	int			color;

	color = get_map_color(data, mini_tmp->pos);
	pos.x = -1;
	while (++pos.x <= data->minimap.zoom)
	{
		pos.y = -1;
		off.x = mini_tmp->offset.x * data->minimap.zoom + pos.x
			- mini_tmp->big_shift - (int)((double)data->minimap.zoom
				* (data->player.pos_x - (int)data->player.pos_x));
		while (++pos.y <= data->minimap.zoom)
		{
			off.y = mini_tmp->offset.y * data->minimap.zoom + pos.y
				- mini_tmp->big_shift - (int)((double)data->minimap.zoom
					* (data->player.pos_y - (int)data->player.pos_y));
			if (off.y >= 0 && off.x >= 0 && off.x < MINIMAP_SIZE
				&& off.y < MINIMAP_SIZE)
			{
				*(unsigned int *)(data->minimap.map_data
						+ (off.y * size_line + off.x * (bpp / 8))) = color;
			}
		}
	}
}

void	draw_player(t_data *data, int sz_line, int bpp, t_minimap_tmp *mn_tmp)
{
	int	x;
	int	y;

	x = 90;
	while (x < 96)
	{
		y = 90;
		while (y < 96)
		{
			*(unsigned int *)(data->minimap.map_data
					+ (y * sz_line + x * (bpp / 8))) = 0xFF4466;
			y++;
		}
		x++;
	}
}

void	create_minimap(t_data *data)
{
	t_minimap_tmp	mini_tmp;
	int				bpp;
	int				endian;
	int				size_line;

	data->minimap.map = mlx_new_image(data->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	data->minimap.map_data = mlx_get_data_addr(data->minimap.map, &bpp,
			&size_line, &endian);
	init_mini_tmp(data, &mini_tmp);
	while (mini_tmp.pos.y <= data->player.pos_y + mini_tmp.shift + 1)
	{
		mini_tmp.offset.x = 0;
		mini_tmp.pos.x = (int)data->player.pos_x - mini_tmp.shift;
		while (mini_tmp.pos.x < data->player.pos_x + mini_tmp.shift + 1)
		{
			fill_pixels(data, size_line, bpp, &mini_tmp);
			mini_tmp.pos.x++;
			mini_tmp.offset.x++;
		}
		mini_tmp.pos.y++;
		mini_tmp.offset.y++;
	}
	draw_player(data, size_line, bpp, &mini_tmp);
}
