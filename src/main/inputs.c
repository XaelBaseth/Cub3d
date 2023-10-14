/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:17:23 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/14 17:03:31 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_game(data);
	if ((keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100 || keysym == 102))
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->cube_info.texture_east, 0, 0);
		// if (keysym == 119 && check_collision(data,
		// 		data->player.pos_x, data->player.pos_y - 1) == 0)
		// 	data->player.pos_y -= 1;
		// else if (keysym == 97 && check_collision(data,
		// 		data->player.pos_x - 1, data->player.pos_y) == 0)
		// 	data->player.pos_x -= 1;
		// else if (keysym == 115 && check_collision(data,
		// 		data->player.pos_x, data->player.pos_y + 1) == 0)
		// 	data->player.pos_y += 1;
		// else if (keysym == 100 && check_collision(data,
		// 		data->player.pos_x + 1, data->player.pos_y) == 0)
		// 	data->player.pos_x += 1;
		// else if (keysym == 102)
		// 	start_attack(data);
		// mlx_put_image_to_window(data->mlx, data->win, data->player.sprite[0],
		// 	data->player.pos_x * 32 - 16, data->player.pos_y * 32 - 16);
	}
	return (0);
}