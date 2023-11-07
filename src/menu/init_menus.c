/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:03:46 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/20 09:17:04 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_level_menu_images(t_data *data)
{
	data->menu.ig_buttons[0].unlit = mlx_xpm_file_to_image(data->mlx,
			"textures/resume_unlit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.ig_buttons[0].lit = mlx_xpm_file_to_image(data->mlx,
			"textures/resume_lit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.ig_buttons[1].unlit = mlx_xpm_file_to_image(data->mlx,
			"textures/controls_unlit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.ig_buttons[1].lit = mlx_xpm_file_to_image(data->mlx,
			"textures/controls_lit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.ig_buttons[2].unlit = mlx_xpm_file_to_image(data->mlx,
			"textures/main_menu_unlit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.ig_buttons[2].lit = mlx_xpm_file_to_image(data->mlx,
			"textures/main_menu_lit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.title_menu = mlx_xpm_file_to_image(data->mlx,
			"textures/menu.xpm", &data->sizes.title_x, &data->sizes.title_y);
}

void	init_menu_images(t_data *data)
{
	data->menu.bg_levels = mlx_xpm_file_to_image(data->mlx,
			"textures/bg_levels.xpm", &data->sizes.win_x, &data->sizes.win_y);
	data->menu.title = mlx_xpm_file_to_image(data->mlx,
			"textures/title.xpm", &data->sizes.title_x, &data->sizes.title_y);
	data->menu.credit = mlx_xpm_file_to_image(data->mlx,
			"textures/credit.xpm", &data->sizes.credit_x,
			&data->sizes.credit_y);
	data->menu.buttons[0].unlit = mlx_xpm_file_to_image(data->mlx,
			"textures/play_unlit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.buttons[0].lit = mlx_xpm_file_to_image(data->mlx,
			"textures/play_lit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.buttons[1].unlit = mlx_xpm_file_to_image(data->mlx,
			"textures/controls_unlit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.buttons[1].lit = mlx_xpm_file_to_image(data->mlx,
			"textures/controls_lit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.buttons[2].unlit = mlx_xpm_file_to_image(data->mlx,
			"textures/quit_unlit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
	data->menu.buttons[2].lit = mlx_xpm_file_to_image(data->mlx,
			"textures/quit_lit.xpm", &data->sizes.button_x,
			&data->sizes.button_y);
}

void	init_menu(t_data *data)
{
	data->menu.cur_button = 0;
	data->menu.cur_selected_level = 0;
	data->menu.buttons[0].pos_x = 321;
	data->menu.buttons[0].pos_y = 287;
	data->menu.buttons[1].pos_x = 321;
	data->menu.buttons[1].pos_y = 412;
	data->menu.buttons[2].pos_x = 321;
	data->menu.buttons[2].pos_y = 531;
	data->menu.ig_buttons[0].pos_x = 321;
	data->menu.ig_buttons[0].pos_y = 287;
	data->menu.ig_buttons[1].pos_x = 321;
	data->menu.ig_buttons[1].pos_y = 412;
	data->menu.ig_buttons[2].pos_x = 321;
	data->menu.ig_buttons[2].pos_y = 531;
	init_menu_images(data);
	open_menu(data, 0);
}
