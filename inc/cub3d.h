/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axel <axel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:19:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/02 10:47:59 by axel             ###   ########.fr       */
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

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/*-------------------------------------------------------------------
									MACROS
---------------------------------------------------------------------*/

typedef struct 	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct 	s_texture
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	int			sky_rgb[3];
	int			floor_rgb[3];
}				t_texture;

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
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
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
	char	dir;
	double	pos_x;
	double	pos_y;
}				t_player;

typedef struct	s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_camera;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		**file_content;
	t_img		img;
	t_camera	camera;
	t_texture	texinfo;
	game_state	state;
	t_block		cube_info;
	t_mapinfo	map_info;
	t_player	player;
	t_ray		ray;
	t_img		minimap;
}				t_data;



/*-------------------------------------------------------------------
									FUNCTIONS
---------------------------------------------------------------------*/

void	print_struct(t_data *data);
void	panic(t_data *data,char *str);
void	init_ray(t_data *data, t_ray *ray, int x);
t_img	init_img(void);
void	put_pixel_img(t_img *img, int x, int y, unsigned int color);
unsigned int	get_color(t_data *data, t_ray *ray);
int	create_tex_rgb(int t, int r, int g, int b);

void	point_rays(t_data *data, t_ray *ray);
void	find_dist_wall(t_data *data, t_ray *ray);
void	find_wall_height(t_ray *ray);
t_img	new_img(void	*mlx);
void	find_wall_pixel(t_data *data, t_ray *ray);
void	render_frame(t_data *data);


void	init_player_pov(t_data *data);
void	init_cub3d(t_data *data);
void	init_mlx(t_data *data);

/* Parsing */
void	read_file_map(t_data *data, char *map_name);
int	save_img(t_data *data, t_img *img, char *arg);
int	save_color(t_data *data, t_color *var, char *arg);
int save_rgb(t_data *data, int (*rgb_arr)[3], char *arg);
void	exit_message(char *msg, int *fd);
int	check_nbr(char *str);

/* Game */
int		exit_game(t_data *data);

/* Inputs */
int	handle_keypress(int keysym, t_data *data);

#endif
