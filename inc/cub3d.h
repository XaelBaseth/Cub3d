/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:19:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 14:15:35 by cpothin          ###   ########.fr       */
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

# include "render.h"
# include "init.h"
# include "input.h"
# include "menu.h"
# include "minimap.h"
# include "parsing.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

/*-----------------------------------------------------------------------------
								MACROS
-----------------------------------------------------------------------------*/
# define SUCCESS 0
# define FAILURE 1

typedef enum g_state
{
	STARTING,
	IN_MENU,
	IN_GAME_MENU,
	IN_LVL_SELECTION,
	IN_CONTROLS,
	IN_GAME_CONTROLS,
	IN_GAME
}				t_game_state;

/*-----------------------------------------------------------------------------
								STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_vector2		t_vector2;
typedef struct s_minimap		t_minimap;
typedef struct s_button			t_button;
typedef struct s_menu			t_menu;
typedef struct s_img			t_img;
typedef struct s_texture		t_texture;
typedef struct s_ray			t_ray;
typedef struct s_mapinfo		t_mapinfo;
typedef struct s_sizes			t_sizes;
typedef struct s_camera			t_camera;
typedef struct s_player			t_player;
typedef struct s_data			t_data;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				win_height;
	int				win_width;
	int				argc;
	char			**file_content;
	t_img			img;
	t_camera		camera;
	t_texture		texinfo;
	t_game_state	state;
	t_mapinfo		map_info;
	t_player		player;
	t_ray			ray;
	t_menu			menu;
	t_sizes			sizes;
	t_minimap		minimap;
	t_vector2		mouse_position;
}					t_data;

/*-----------------------------------------------------------------------------
								FUNTIONS
-----------------------------------------------------------------------------*/
void	print_struct(t_data *data);
void	panic(t_data *data, char *str);
int		window_loop(t_data *data);
int		exit_game(t_data *data);
void	unload(t_data *data);
void	start_level(t_data *data, char *map_name);

#endif
