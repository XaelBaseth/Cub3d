/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:19:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/10/16 15:01:52 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*-----------------------------------------------------------------------------
								STRUCTURES
-----------------------------------------------------------------------------*/

# include "../lib/libft/inc/ft_gc_alloc.h"
# include "../lib/libft/inc/ft_printf.h"
# include "../lib/libft/inc/libft.h"
# include "../lib/libft/inc/get_next_line.h"
# include "../lib/minilibx/mlx.h"

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

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

typedef enum	game_state
{
	IN_MENU,
	IN_LVL_SELECTION,
	IN_GAME
}				game_state;

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

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**file_content;
	game_state	state;
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
