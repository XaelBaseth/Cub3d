/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:37:10 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/13 11:35:34 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/*-----------------------------------------------------------------------------
									LIBRAIRIES
-----------------------------------------------------------------------------*/
# include "cub3d.h"
# include "minimap.h"

/*-----------------------------------------------------------------------------
									MACRO
-----------------------------------------------------------------------------*/

# define IMG_SIZE 128
# define WHITE 16777215
# define GREY 2236962
/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data			t_data;

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

typedef struct s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_camera;

typedef struct s_player
{
	char		dir;
	double		pos_x;
	double		pos_y;
	t_vector2	movement;
}				t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*name;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_texture
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	int			sky_rgb[3];
	int			floor_rgb[3];
	void		*animations[8];
}				t_texture;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/

void			point_rays(t_data *data, t_ray *ray);
void			find_dist_wall(t_data *data, t_ray *ray);
void			find_wall_height(t_ray *ray);
void			find_wall_pixel(t_data *data, t_ray *ray, int x);
void			render_frame(t_data *data);
void			put_pixel_img(t_img *img, int x, int y, unsigned int color);
unsigned int	get_color(t_data *data, t_ray *ray);
int				create_tex_rgb(int r, int g, int b);
void			animate_wall(t_data *data);
void			save_wall_frames(t_data *data);
void			delete_animations(t_data *data);

#endif