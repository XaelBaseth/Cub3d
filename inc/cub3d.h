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

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

/*-------------------------------------------------------------------
									MACROS
---------------------------------------------------------------------*/

# define MAP_PATH "maps/"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define BUFFER 4096
# define IMG_SIZE 128

# define SUCCESS 0
# define FAILURE 1

/*-------------------------------------------------------------------
									MACROS
---------------------------------------------------------------------*/

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_block
{
	void	*texture_north;
	void	*texture_south;
	void	*texture_east;
	void	*texture_west;
	int		width;
	int		height;
}				t_block;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**level;
	int			height;
	int			width;
	int			index_end_of_map;
	t_color		ceiling_color;
	t_color		floor_color;
}				t_mapinfo;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**file_content;
	t_block		cube_info;
	t_mapinfo	map_info;
	t_player	player;
	t_ray		ray;

}				t_data;

/*-------------------------------------------------------------------
									FUNCTIONS
---------------------------------------------------------------------*/

void	init_ray(t_ray *ray);

/* Parsing */
void	read_file_map(t_data *data, char *map_name);

/* Game */
int		exit_game(t_data *data);

/* Inputs */
int	handle_keypress(int keysym, t_data *data);


#endif
