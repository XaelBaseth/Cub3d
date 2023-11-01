#include "../../inc/cub3d.h"

void	panic(t_data *data,char *str)
{
	gc_free_all();
	ft_printf("\033[31mError!\n%s\n\033[0m", str);
	exit_game(data);
}
