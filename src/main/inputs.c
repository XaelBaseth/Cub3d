/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:23 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/07 17:01:12 by cpothin          ###   ########.fr       */
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

int	handle_mouse(int x, int y, t_data *data)
{
	if (data->state != IN_GAME)
		return (FAILURE);
	if (x != data->mouse_position.x)
	{
		if (x < data->mouse_position.x)
			rotate_player(data, 1);
		else
			rotate_player(data, -1);
		data->mouse_position.x = x;
		if (data->mouse_position.x < WIN_WIDTH / 2 - 100)
			mlx_mouse_move(data->mlx, data->win,
			WIN_WIDTH / 2 + 50, WIN_HEIGHT / 2);
		else if (data->mouse_position.x > WIN_WIDTH / 2 + 100)
			mlx_mouse_move(data->mlx, data->win,
			WIN_WIDTH / 2 - 50, WIN_HEIGHT / 2);
		if (data->mouse_position.y < WIN_HEIGHT / 2 - 100)
			mlx_mouse_move(data->mlx, data->win,
			WIN_WIDTH / 2, WIN_HEIGHT / 2 + 50);
		else if (data->mouse_position.y > WIN_HEIGHT / 2 + 100)
			mlx_mouse_move(data->mlx, data->win,
			WIN_WIDTH / 2, WIN_HEIGHT / 2 - 50);
	}
}
