/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:29:21 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/10 17:54:07 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	prepare_level(t_data *data, char *level_name)
{
	unload(data);
	start_level(data, level_name);
}

void	return_game(t_data *data)
{
	data->state = IN_GAME;
	create_minimap(data);
}

void	trigger_menu_ig(t_data *data, bool is_on)
{
	if (is_on)
	{
		open_menu(data, data->menu.cur_button);
		data->state = IN_GAME_MENU;
	}
	else
		return_game(data);
}

void	trigger_controls(t_data *data, bool is_on, bool from_menu)
{
	if (is_on)
	{
		if (from_menu)
			data->state = IN_CONTROLS;
		else
			data->state = IN_GAME_CONTROLS;
		mlx_put_image_to_window(data->mlx, data->win,
			data->menu.bg_controls, 0, 0);
	}
	else
	{
		if (data->state == IN_CONTROLS)
		{
			data->state = IN_MENU;
			open_menu(data, 1);
		}
		else
			trigger_menu_ig(data, true);
	}
}
