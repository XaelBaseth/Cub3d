/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:10:34 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/08 18:35:20 by axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	window_loop(t_data *data)
{
	if (data->state != IN_GAME)
		return (FAILURE);
	create_minimap(data);
	data->player.has_moved += move_player(data);
	if (data->player.has_moved == 0)
		return (0);
	render_frame(data);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->minimap.map);
	data->minimap.map = NULL;
	data->img.img = NULL;
	return (SUCCESS);
}

void	hook_and_run(t_data *data)
{
	mlx_mouse_hide(data->mlx, data->win);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, handle_mouse, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_hook(data->win, 17, 0, &exit_game, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_sizes(&data);
	data.argc = argc;
	if (argc == 1 || argc == 2)
		init_game(&data);
	else
		ft_printf("Error\n\t0 or 1 argument needed!\n");
	if (argc == 2)
	{
		start_level(&data, argv[1]);
	}
	else if (argc == 1)
	{
		data.state = IN_MENU;
		init_menu(&data);
	}
	else
		exit_game(&data);
	hook_and_run(&data);
	exit_game(&data);
}
