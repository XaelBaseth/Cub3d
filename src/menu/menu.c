/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:25:46 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/06 10:30:56 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	open_ig_menu(t_data *data, int hl_button)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->menu.ig_buttons[i].unlit, data->menu.ig_buttons[i].pos_x,
			data->menu.ig_buttons[i].pos_y);
	}
	mlx_put_image_to_window(data->mlx, data->win,
		data->menu.ig_buttons[hl_button].lit,
		data->menu.ig_buttons[hl_button].pos_x,
		data->menu.ig_buttons[hl_button].pos_y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->menu.title_menu, 300, 70);
}

void	open_main_menu(t_data *data, int hl_button)
{
	int	i;

	i = -1;
	while (++i < 3)
		mlx_put_image_to_window(data->mlx, data->win,
			data->menu.buttons[i].unlit, data->menu.buttons[i].pos_x,
			data->menu.buttons[i].pos_y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->menu.buttons[hl_button].lit,
		data->menu.buttons[hl_button].pos_x,
		data->menu.buttons[hl_button].pos_y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->menu.credit, 770, 695);
	mlx_put_image_to_window(data->mlx, data->win,
		data->menu.title, 300, 70);
}

void	open_menu(t_data *data, int hl_button)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->menu.bg_menu, 0, 0);
	if (data->state == IN_GAME || data->state == IN_GAME_CONTROLS)
		open_ig_menu(data, hl_button);
	else
		open_main_menu(data, hl_button);
}
