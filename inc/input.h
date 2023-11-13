/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:44:53 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/13 08:20:10 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

/*-----------------------------------------------------------------------------
									LIBRAIRIES
-----------------------------------------------------------------------------*/
# include "cub3d.h"

/*-----------------------------------------------------------------------------
									MACRO
-----------------------------------------------------------------------------*/

# define ROT_SPEED 0.03
# define MOVESPEED 0.04f
# define MARGIN	0.2f


/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data			t_data;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/

int		rotate_player(t_data *data, double rotdir);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_mouse(int x, int y, t_data *data);
void	press_in_game_menu(int keysym, t_data *data);
void	press_in_game(int keysym, t_data *data);
void	release_in_game(int keysym, t_data *data);
void	release_in_game(int keysym, t_data *data);
void	press_in_menu(int keysym, t_data *data);
void	press_in_controls(int keysym, t_data *data);
void	press_in_lvl_selection(int keysym, t_data *data);
int		validate_move(t_data *data, double new_x, double new_y);
int		move_player(t_data *data);

#endif