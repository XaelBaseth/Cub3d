/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:23 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/14 17:35:40 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	press_in_lvl_selection(int keysym, t_data *data)
{
	if (keysym == XK_w)
		ft_printf("\nw pressed in level selection menu\n");
	else if (keysym == XK_a)
		ft_printf("\na pressed in level selection menu\n");
	else if (keysym == XK_s)
		ft_printf("\ns pressed in level selection menu\n");
	else if (keysym == XK_d)
		ft_printf("\nd pressed in level selection menu\n");
}

/* Checks which key is pressed when inside the menu */
static void	press_in_menu(int keysym, t_data *data)
{
	if (keysym == XK_w)
		ft_printf("\nw pressed in menu\n");
	else if (keysym == XK_a)
		ft_printf("\na pressed in menu\n");
	else if (keysym == XK_s)
		ft_printf("\ns pressed in menu\n");
	else if (keysym == XK_d)
		ft_printf("\nd pressed in menu\n");
}

static void	press_in_game(int keysym, t_data *data)
{
	if (keysym == XK_w)
		ft_printf("\nw pressed in game\n");
	else if (keysym == XK_a)
		ft_printf("\na pressed in game\n");
	else if (keysym == XK_s)
		ft_printf("\ns pressed in game\n");
	else if (keysym == XK_d)
		ft_printf("\nd pressed in game\n");
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_game(data);
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->cube_info.texture_east, 0, 0);
		if (data->state == IN_MENU)
			press_in_menu(keysym, data);
		else if (data->state == IN_LVL_SELECTION)
			press_in_lvl_selection(keysym, data);
		else if (data->state == IN_GAME)
			press_in_game(keysym, data);
	}
	return (0);
}