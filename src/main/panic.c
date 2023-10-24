#include "../../inc/cub3d.h"

void	panic(t_data *data, char *err_msg)
{
	ft_printf("\033[31m\nError: %s\n\033[0m", err_msg);
	exit_game(data);
}