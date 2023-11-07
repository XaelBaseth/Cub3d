/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:10:34 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/07 16:34:13 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	window_loop(t_data *data)
{
	if (data->state != IN_GAME)
		return (FAILURE);
	usleep(1000000 / FPS);
	render_frame(data);
	create_minimap(data);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_image(data->mlx, data->minimap.map);
	data->minimap.map = NULL;
	data->img.img = NULL;
	return (SUCCESS);
}

void	init_sizes(t_data *data)
{
	data->sizes.button_x = B_SIZE_W;
	data->sizes.button_y = B_SIZE_H;
	data->sizes.win_x = WIN_WIDTH;
	data->sizes.win_y = WIN_HEIGHT;
	data->sizes.title_x = 351;
	data->sizes.title_y = 100;
	data->sizes.credit_x = 190;
	data->sizes.credit_y = 25;
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	data->menu.bg_controls = mlx_xpm_file_to_image(data->mlx,
			"textures/bg_controls.xpm", &data->sizes.win_x, &data->sizes.win_y);
	data->menu.bg_menu = mlx_xpm_file_to_image(data->mlx,
			"textures/bg_menu.xpm", &data->sizes.win_x, &data->sizes.win_y);
	data->mouse_position.x = 0;
	data->mouse_position.y = 0;
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_position.x,
		&data->mouse_position.y);
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
	mlx_mouse_hide(data.mlx, data.win);
	mlx_mouse_move(data.mlx, data.win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, handle_mouse, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, 17, 0, &exit_game, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
}
