/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:50:41 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 10:07:20 by acharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

/*-----------------------------------------------------------------------------
									LIBRAIRIES
-----------------------------------------------------------------------------*/
# include "cub3d.h"
# include <stdbool.h>
/*-----------------------------------------------------------------------------
									MACRO
-----------------------------------------------------------------------------*/

# define B_SIZE_H 91
# define B_SIZE_W 318

typedef enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}				t_direction;

/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data	t_data;

typedef struct s_sizes
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

typedef struct s_button
{
	void	*unlit;
	void	*lit;
	int		pos_x;
	int		pos_y;
}				t_button;

typedef struct s_menu
{
	int			cur_button;
	int			cur_selected_level;
	void		*bg_menu;
	void		*bg_levels;
	void		*bg_controls;
	void		*title;
	void		*title_menu;
	void		*credit;
	t_button	buttons[3];
	t_button	ig_buttons[3];
}				t_menu;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/

void	trigger_controls(t_data *data, bool is_on, bool from_menu);
void	trigger_level_selection(t_data *data, bool is_on);
void	open_menu(t_data *data, int hl_button);
void	trigger_menu_ig(t_data *data, bool is_on);
void	return_game(t_data *data);
void	prepare_level(t_data *data, char *level_name);
void	trigger_menu_ig(t_data *data, bool is_on);
void	trigger_level_selection(t_data *data, bool is_on);
void	trigger_controls(t_data *data, bool is_on, bool from_menu);
void	highlight_button(t_data *data, t_direction direction,
			t_button *buttons);

#endif