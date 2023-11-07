/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:19:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/07 18:21:45 by cpothin          ###   ########.fr       */
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

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

/*-------------------------------------------------------------------
									MACROS
---------------------------------------------------------------------*/

# define ROT_SPEED 0.03
# define MAP_PATH "maps/"
# define WIN_WIDTH 960
# define WIN_HEIGHT 720
# define MINIMAP_SIZE 192
# define B_SIZE_H 91
# define B_SIZE_W 318

# define BUFFER 4096
# define IMG_SIZE 128

# define SUCCESS 0
# define FAILURE 1

# define WHITE 16777215
# define GREY 2236962

/*-------------------------------------------------------------------
									STRUCTURES
---------------------------------------------------------------------*/

typedef	struct s_vector2
{
	int	x;
	int	y;
}				t_vector2;

typedef struct s_minimap
{
	t_vector2	up_left;
	t_vector2	up_rt;
	t_vector2	lwr_lft;
	t_vector2	lwr_rt;
	int			zoom;
	t_vector2	center;
	t_vector2	map_size;
	void		*map;
	char		*map_data;
}				t_minimap;

typedef enum	direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				e_direction;

/* Play, Controls, Quit */
typedef struct	s_button
{
	void	*unlit;
	void	*lit;
	int		pos_x;
	int		pos_y;
}				t_button;

typedef struct	s_menu
{
	int		cur_button;
	int		cur_selected_level;
	void	*bg_menu;
	void	*bg_levels;
	void	*bg_controls;
	void	*title;
	void	*title_menu;
	void	*credit;
	t_button	buttons[3];
	t_button	ig_buttons[3];
}				t_menu;

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

typedef enum	g_state
{
	STARTING,
	IN_MENU,
	IN_GAME_MENU,
	IN_LVL_SELECTION,
	IN_CONTROLS,
	IN_GAME_CONTROLS,
	IN_GAME
}				game_state;

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

/* Temp vars to help to maintain a clean norminette. */
typedef struct	s_minimap_tmp
{
	t_vector2	offset;
	t_vector2	pos;
	int			shift;
	int			big_shift;
}				t_minimap_tmp;

typedef struct	s_sizes
{
	int	win_x;
	int	win_y;
	int	title_x;
	int	title_y;
	int	button_x;
	int	button_y;
	int	credit_x;
	int	credit_y;
}				t_sizes;

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
	int			argc;
	char		**file_content;
	t_img		img;
	t_camera	camera;
	t_texture	texinfo;
	game_state	state;
	// t_block		cube_info;
	t_mapinfo	map_info;
	t_player	player;
	t_ray		ray;
	t_menu		menu;
	t_sizes		sizes;
	t_minimap	minimap;
	t_vector2	mouse_position;
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
void	find_wall_pixel(t_data *data, t_ray *ray);
void	render_frame(t_data *data);


void	init_player_pov(t_data *data);
void	init_cub3d(t_data *data);
int		window_loop(t_data *data);

/* Move player */
int	rotate_player(t_data *data, double rotdir);

/* Parsing */
void	read_file_map(t_data *data, char *map_name);
int	save_img(t_data *data, t_img *img, char *arg);
int	save_color(t_data *data, t_color *var, char *arg);
int save_rgb(t_data *data, int *rgb_arr, char *arg);
void	exit_message(char *msg, int *fd);
int	check_nbr(char *str);

/* Unload */
int		exit_game(t_data *data);
void	unload(t_data *data);

/* Game */
void	start_level(t_data *data, char *map_name);

/* Inputs */
int		handle_keypress(int keysym, t_data *data);
int		handle_mouse(int x, int y, t_data *data);

/* Press in */
void	press_in_game_menu(int keysym, t_data *data);
void	press_in_game(int keysym, t_data *data);
void	press_in_menu(int keysym, t_data *data);
void	press_in_controls(int keysym, t_data *data);
void	press_in_lvl_selection(int keysym, t_data *data);

/* Menu */
void	trigger_controls(t_data *data, bool is_on, bool from_menu);
void	trigger_level_selection(t_data *data, bool is_on);
void	open_menu(t_data *data, int hl_button);
void	trigger_menu_ig(t_data *data, bool is_on);

/* Init menus */
void	init_menu(t_data *data);
void	init_menu_images(t_data *data);
void	init_level_menu_images(t_data *data);

/* Menu utils */
void	return_game(t_data *data);
void	prepare_level(t_data *data, char *level_name);
void	trigger_menu_ig(t_data *data, bool is_on);
void	trigger_level_selection(t_data *data, bool is_on);
void	trigger_controls(t_data *data, bool is_on, bool from_menu);

/* Highlight buttons */
void	highlight_button(t_data *data, e_direction direction, t_button *buttons);

/* Minimap */
void	init_minimap(t_data *data);
void	draw_outline(t_data *data);
// void	draw_minimap(t_data *data);
void	create_minimap(t_data *data);
t_vector2		max_map_size(t_data *data);

/* Minimap utils */
void	zoom_in(t_data *data);
void	zoom_out(t_data *data);
void	init_mini_tmp(t_data *data, t_minimap_tmp *mini_tmp);
t_vector2	max_map_size(t_data *data);

#endif
