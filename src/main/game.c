/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:12:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/21 11:19:58 by axel             ###   ########.fr       */
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
	mlx_destroy_image(data->mlx, data->cube_info.texture_east);
	mlx_destroy_image(data->mlx, data->cube_info.texture_north);
	mlx_destroy_image(data->mlx, data->cube_info.texture_south);
	mlx_destroy_image(data->mlx, data->cube_info.texture_west);
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
