/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:33:05 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/08 13:29:42 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	press_in_lvl_selection(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_Return || keysym == XK_space)
		trigger_level_selection(data, false);
	else if (keysym == XK_w)
		ft_printf("\nw pressed in level selection menu\n");
	else if (keysym == XK_a)
		ft_printf("\na pressed in level selection menu\n");
	else if (keysym == XK_s)
		ft_printf("\ns pressed in level selection menu\n");
	else if (keysym == XK_d)
		ft_printf("\nd pressed in level selection menu\n");
}

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
		move_up(data);
	else if (keysym == XK_a)
		move_left(data);
	else if (keysym == XK_s)
		move_down(data);
	else if (keysym == XK_d)
		move_right(data);	
	else if (keysym == XK_KP_Add)
		zoom_in(data);
	else if (keysym == XK_KP_Subtract)
		zoom_out(data);
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
