#include "../../inc/cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		panic(data, "Could not start the minilibx.");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		panic(data, "Could not start the minilibx.");
}

void	init_cub3d(t_data *data)
{
	data->file_content = NULL;
	data->img = init_img();
}
