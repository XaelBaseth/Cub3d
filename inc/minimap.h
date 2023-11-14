/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:00:26 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/14 10:30:45 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

/*-----------------------------------------------------------------------------
									LIBRAIRIES
-----------------------------------------------------------------------------*/
# include "cub3d.h"

/*-----------------------------------------------------------------------------
									MACRO
-----------------------------------------------------------------------------*/

# define MINIMAP_SIZE 192

/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data			t_data;

typedef struct s_vector2
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
	// void		*map;
	// char		*map_data;
}				t_minimap;

typedef struct s_minimap_tmp
{
	t_vector2	offset;
	t_vector2	pos;
	int			shift;
	int			big_shift;
}				t_minimap_tmp;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/

void			draw_outline(t_data *data);
void			create_minimap(t_data *data);
t_vector2		max_map_size(t_data *data);
void			zoom_in(t_data *data);
void			zoom_out(t_data *data);
t_vector2		max_map_size(t_data *data);

#endif