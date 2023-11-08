/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:39:36 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 10:03:30 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

/*-----------------------------------------------------------------------------
									LIBRAIRIES
-----------------------------------------------------------------------------*/
# include "cub3d.h"

/*-----------------------------------------------------------------------------
									MACRO
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data			t_data;
typedef struct s_ray			t_ray;
typedef struct s_img			t_img;
typedef struct s_minimap_tmp	t_minimap_tmp;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/

void	init_sizes(t_data *data);
void	init_game(t_data *data);
void	init_ray(t_data *data, t_ray *ray, int x);
t_img	init_img(void);
void	init_player_pov(t_data *data);
void	init_cub3d(t_data *data);
void	init_menu(t_data *data);
void	init_menu_images(t_data *data);
void	init_level_menu_images(t_data *data);
void	init_minimap(t_data *data);
void	init_mini_tmp(t_data *data, t_minimap_tmp *mini_tmp);

#endif