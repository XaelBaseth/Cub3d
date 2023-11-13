/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:12:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/13 11:17:41 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	start_level(t_data *data, char *map_name)
{
	data->exit = false;
	if (!check_map_extension(map_name))
	{
		ft_printf("Error:\n\tThe file extension must be \".cub\"!\n");
		exit_game(data);
	}
	data->state = IN_GAME;
	if (BONUS && data->argc == 1)
		init_level_menu_images(data);
	if (BONUS)
		save_wall_frames(data);
	init_cub3d(data);
	read_file_map(data, map_name);
	init_doors(data);
	if (BONUS)
		init_minimap(data);
	mlx_loop_hook(data->mlx, &window_loop, data);
}
