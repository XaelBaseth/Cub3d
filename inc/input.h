/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:44:53 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 13:28:01 by acharlot         ###   ########.fr       */
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


/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data			t_data;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/

int		rotate_player(t_data *data, double rotdir);
int		handle_keypress(int keysym, t_data *data);
int		handle_mouse(int x, int y, t_data *data);
void	press_in_game_menu(int keysym, t_data *data);
void	press_in_game(int keysym, t_data *data);
void	press_in_menu(int keysym, t_data *data);
void	press_in_controls(int keysym, t_data *data);
void	press_in_lvl_selection(int keysym, t_data *data);
void	move_up(t_data *this);
void	move_left(t_data *this);
void	move_down(t_data *this);
void	move_right(t_data *this);

#endif