/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:23 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/10 11:25:24 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (data->state == IN_MENU)
		press_in_menu(keysym, data);
	else if (data->state == IN_GAME_MENU)
		press_in_game_menu(keysym, data);
	else if (data->state == IN_LVL_SELECTION)
		press_in_lvl_selection(keysym, data);
	else if (data->state == IN_CONTROLS || data->state == IN_GAME_CONTROLS)
		press_in_controls(keysym, data);
	else if (data->state == IN_GAME)
		press_in_game(keysym, data);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (data->state == IN_GAME)
		release_in_game(keysym, data);
	return (0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	if (data->state != IN_GAME || !BONUS)
		return (FAILURE);
	if (x != data->mouse_position.x || y != data->mouse_position.y)
	{
		rotate_player(data, (double)(x - data->mouse_position.x) / 20.0);
		data->mouse_position.y = WIN_HEIGHT / 2;
		data->mouse_position.x = WIN_WIDTH / 2;
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2,
			WIN_HEIGHT / 2);
	}
}
