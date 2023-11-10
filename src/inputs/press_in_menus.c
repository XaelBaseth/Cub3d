/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_in_menus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:33:05 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/10 17:54:54 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	press_in_controls(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_Return || keysym == XK_space)
		trigger_controls(data, false, false);
}

/* Checks which key is pressed when inside the menu */
void	press_in_menu(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		highlight_button(data, UP, data->menu.buttons);
	else if (keysym == XK_s || keysym == XK_Down)
		highlight_button(data, DOWN, data->menu.buttons);
	else if (keysym == XK_Return || keysym == XK_space)
	{
		if (data->menu.cur_button == 0)
		{
			unload(data);
			start_level(data, "test.cub");
		}
		else if (data->menu.cur_button == 1)
			trigger_controls(data, true, true);
		else if (data->menu.cur_button == 2)
			exit_game(data);
	}
	else if (keysym == XK_Escape)
		exit_game(data);
}
