/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:20:54 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/07 10:20:29 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	free_level(t_data *data)
{
	int	i;

	if (data->map_info.level)
	{
		i = 0;
		while (data->map_info.level[i])
			gc_free(data->map_info.level[i++]);
		gc_free(data->map_info.level);
	}
	if (data->file_content)
	{
		i = 0;
		while (data->file_content[i])
			gc_free(data->file_content[i++]);
		gc_free(data->file_content);
	}
}

static void	unload_level(t_data *data)
{
	mlx_destroy_image(data->mlx, data->texinfo.north.img);
	mlx_destroy_image(data->mlx, data->texinfo.south.img);
	mlx_destroy_image(data->mlx, data->texinfo.east.img);
	mlx_destroy_image(data->mlx, data->texinfo.west.img);
	free_level(data);
	if (data->argc == 2)
		return ;
	mlx_destroy_image(data->mlx, data->menu.ig_buttons[0].lit);
	mlx_destroy_image(data->mlx, data->menu.ig_buttons[0].unlit);
	mlx_destroy_image(data->mlx, data->menu.ig_buttons[1].lit);
	mlx_destroy_image(data->mlx, data->menu.ig_buttons[1].unlit);
	mlx_destroy_image(data->mlx, data->menu.ig_buttons[2].lit);
	mlx_destroy_image(data->mlx, data->menu.ig_buttons[2].unlit);
	mlx_destroy_image(data->mlx, data->menu.title_menu);
}

static void	unload_menu(t_data *data)
{
	mlx_destroy_image(data->mlx, data->menu.buttons[0].lit);
	mlx_destroy_image(data->mlx, data->menu.buttons[0].unlit);
	mlx_destroy_image(data->mlx, data->menu.buttons[1].lit);
	mlx_destroy_image(data->mlx, data->menu.buttons[1].unlit);
	mlx_destroy_image(data->mlx, data->menu.buttons[2].lit);
	mlx_destroy_image(data->mlx, data->menu.buttons[2].unlit);
	mlx_destroy_image(data->mlx, data->menu.bg_levels);
	mlx_destroy_image(data->mlx, data->menu.title);
	mlx_destroy_image(data->mlx, data->menu.credit);
}

void	unload(t_data *data)
{
	if (data->state == IN_GAME || data->state == IN_GAME_MENU)
		unload_level(data);
	else if (data->state == IN_MENU)
		unload_menu(data);
}

int	exit_game(t_data *data)
{
	unload(data);
	gc_free_all();
	if (data->argc == 1)
	{
		mlx_destroy_image(data->mlx, data->menu.bg_menu);
		mlx_destroy_image(data->mlx, data->menu.bg_controls);
	}
	if (data->state != STARTING)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
