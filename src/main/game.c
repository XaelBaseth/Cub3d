/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:12:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/09 15:13:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	start_level(t_data *data, char *map_name)
{
	data->state = IN_GAME;
	init_level_menu_images(data);
	init_cub3d(data);
	read_file_map(data, map_name);
	if (BONUS)
		init_minimap(data);
	mlx_loop_hook(data->mlx, &window_loop, data);
}
