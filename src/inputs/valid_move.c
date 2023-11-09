#include "../../inc/cub3d.h"

static bool	wall_collision(t_data *data, double x, double y)
{
	if (data->map_info.level[(int)y][(int)x] != '1')
		return (false);
	return (true);
}

static bool	in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_info.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map_info.height - 0.25)
		return (false);
	return (true);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (wall_collision(data, new_x, data->player.pos_y) &&
		in_map(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (wall_collision(data, data->player.pos_x, new_y) &&
		in_map(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}