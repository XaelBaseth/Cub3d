/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:41:26 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/08 10:06:01 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	highlight_next(t_data *data, t_button *buttons, int nb)
{
	t_button	*button;

	button = &buttons[data->menu.cur_button];
	mlx_put_image_to_window(data->mlx, data->win,
		button->unlit, button->pos_x, button->pos_y);
	data->menu.cur_button += nb;
	button = &buttons[data->menu.cur_button];
	mlx_put_image_to_window(data->mlx, data->win,
		button->lit, button->pos_x, button->pos_y);
}

void	highlight_button(t_data *data, t_direction direction, t_button *buttons)
{
	t_button	*button;

	if (direction == UP)
	{
		if (data->menu.cur_button > 0)
			highlight_next(data, buttons, -1);
	}
	else if (direction == DOWN)
	{
		if (data->menu.cur_button < 2)
			highlight_next(data, buttons, 1);
	}
}
