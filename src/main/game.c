/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:12:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/24 14:44:39 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	free_level(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_info.level[i])
		gc_free(data->map_info.level[i++]);
	gc_free(data->map_info.level);
	// data->map_info.level = NULL;
	i = 0;
	while (data->file_content[i])
		gc_free(data->file_content[i++]);
	gc_free(data->file_content);
	// data->file_content = NULL;
}

static void	free_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->cube_info.textures_paths[0]);
	mlx_destroy_image(data->mlx, data->cube_info.textures_paths[1]);
	mlx_destroy_image(data->mlx, data->cube_info.textures_paths[2]);
	mlx_destroy_image(data->mlx, data->cube_info.textures_paths[3]);
}

int	exit_game(t_data *data)
{
	free_level(data);
	free_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
