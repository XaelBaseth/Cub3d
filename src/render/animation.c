/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:39:03 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/13 11:12:02 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	delete_animations(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
		mlx_destroy_image(data->mlx, data->texinfo.animations[i++]);
}

void	anim_up(t_data *data, int *i, bool *up)
{
	data->texinfo.north.img = data->texinfo.animations[*i];
	data->texinfo.north.addr = mlx_get_data_addr
		(data->texinfo.north.img, &data->texinfo.north.bpp,
			&data->texinfo.north.size_line,
			&data->texinfo.north.endian);
}

void	anim_down(t_data *data, int *i, bool *up)
{
	data->texinfo.north.img = data->texinfo.animations[*i];
	data->texinfo.north.addr = mlx_get_data_addr
		(data->texinfo.north.img, &data->texinfo.north.bpp,
			&data->texinfo.north.size_line,
			&data->texinfo.north.endian);
}

void	animate_wall(t_data *data)
{
	static int	wait;
	static bool	up;
	static int	i;

	if (wait == 10)
	{
		if (!up)
		{
			anim_up(data, &i, &up);
			i++;
			if (i == 7)
				up = !up;
		}
		else
		{
			anim_down(data, &i, &up);
			i--;
			if (i == 0)
				up = !up;
		}
		wait = 0;
	}
	wait++;
}

void	save_wall_frames(t_data *data)
{
	int	size;

	size = IMG_SIZE;
	data->texinfo.animations[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim0.xpm", &size, &size);
	data->texinfo.animations[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim1.xpm", &size, &size);
	data->texinfo.animations[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim2.xpm", &size, &size);
	data->texinfo.animations[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim3.xpm", &size, &size);
	data->texinfo.animations[4] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim4.xpm", &size, &size);
	data->texinfo.animations[5] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim5.xpm", &size, &size);
	data->texinfo.animations[6] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim6.xpm", &size, &size);
	data->texinfo.animations[7] = mlx_xpm_file_to_image(data->mlx,
			"textures/anim7.xpm", &size, &size);
}
