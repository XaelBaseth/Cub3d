/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:10:34 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/14 17:05:15 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_vars(t_data *data)
{
	int i = 0;
	
	ft_printf("Vars:\n\n");
	ft_printf("Ceiling color: %d, %d, %d\nFloor color: %d, %d, %d\n",
		data->map_info.ceiling_color.r, data->map_info.ceiling_color.g, data->map_info.ceiling_color.b,
		data->map_info.floor_color.r, data->map_info.floor_color.g, data->map_info.floor_color.b);
	ft_printf("\n--------------------\nFile content:\n\n");
	while (data->file_content[i])
		ft_printf("%s\n", data->file_content[i++]);
	ft_printf("\n--------------------\nMap content:\n\n");
	i = 0;
	while (data->map_info.level[i])
		ft_printf("%s\n", data->map_info.level[i++]);

}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.mlx = mlx_init();
	read_file_map(&data, argv[1]);
	// print_vars(&data);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, 17, 0, &exit_game, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
}