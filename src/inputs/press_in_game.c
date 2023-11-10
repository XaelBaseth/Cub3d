/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_in_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:21:13 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/09 16:22:15 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	press_in_game(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		if (data->argc == 2)
			exit_game(data);
		else
			trigger_menu_ig(data, true);
	}
	if (keysym == XK_w)
		data->player.movement.y -= 1;
	else if (keysym == XK_a)
		data->player.movement.x -= 1;
	else if (keysym == XK_s)
		data->player.movement.y += 1;
	else if (keysym == XK_d)
		data->player.movement.x += 1;
	if (keysym == XK_KP_Add)
		zoom_in(data);
	else if (keysym == XK_KP_Subtract)
		zoom_out(data);
	if (keysym == XK_Right)
		rotate_player(data, -1);
	else if (keysym == XK_Left)
		rotate_player(data, 1);
}

void	release_in_game(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->player.movement.y += 1;
	else if (keysym == XK_a)
		data->player.movement.x += 1;
	else if (keysym == XK_s)
		data->player.movement.y -= 1;
	else if (keysym == XK_d)
		data->player.movement.x -= 1;
}

/* Checks which key is pressed when inside the game menu */
void	press_in_game_menu(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		highlight_button(data, UP, data->menu.ig_buttons);
	else if (keysym == XK_s || keysym == XK_Down)
		highlight_button(data, DOWN, data->menu.ig_buttons);
	else if (keysym == XK_Return || keysym == XK_space)
	{
		if (data->menu.cur_button == 0)
			trigger_menu_ig(data, false);
		else if (data->menu.cur_button == 1)
			trigger_controls(data, true, false);
		else if (data->menu.cur_button == 2)
		{
			init_menu(data);
			open_menu(data, 0);
			unload(data);
			data->state = IN_MENU;
		}
	}
	else if (keysym == XK_Escape)
		trigger_menu_ig(data, false);
}
