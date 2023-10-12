#ifndef CUB3D_H
# define CUB3D_H

/*-------------------------------------------------------------------
									LIBRAIRIES
---------------------------------------------------------------------*/

# include "../lib/minilibx/mlx.h"
# include "../lib/libft/inc/libft.h"
# include "../lib/libft/inc/ft_gc_alloc.h"
# include "../lib/libft/inc/ft_printf.h"
# include "../lib/libft/inc/get_next_line.h"
# include "raycasting.h"
# include "player.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

/*-------------------------------------------------------------------
									MACROS
---------------------------------------------------------------------*/
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define SUCCESS 0
# define FAILURE 1

/*-------------------------------------------------------------------
									MACROS
---------------------------------------------------------------------*/

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}				t_mapinfo;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;

}				t_data;

/*-------------------------------------------------------------------
									FUNCTIONS
---------------------------------------------------------------------*/

void	init_ray(t_ray *ray);

#endif
