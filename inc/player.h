/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:31:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/10/16 14:31:40 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

/*-------------------------------------------------------------------
									STRUCTURES
---------------------------------------------------------------------*/


typedef struct	s_pos
{
	int		pos_x;
	int		pos_y;
	double	sub_x;
	double	sub_y;
	double	rotation;
}				t_pos;

typedef struct	s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;

#endif