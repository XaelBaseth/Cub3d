/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:07:53 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/11 14:54:20 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*-----------------------------------------------------------------------------
									LIBRAIRIES
-----------------------------------------------------------------------------*/
# include "cub3d.h"

/*-----------------------------------------------------------------------------
									MACRO
-----------------------------------------------------------------------------*/
# define MAP_PATH "maps/"
# define WIN_WIDTH 960
# define WIN_HEIGHT 720
# define BUFFER 4096

/*-----------------------------------------------------------------------------
									STRUCTURES
-----------------------------------------------------------------------------*/
typedef struct s_img	t_img;
typedef struct s_data	t_data;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**level;
	int			height;
	int			width;
	int			index_end_of_map;
}				t_mapinfo;

/*-----------------------------------------------------------------------------
									FUNCTIONS
-----------------------------------------------------------------------------*/
void	read_file_map(t_data *data, char *map_name);
int		save_img(t_data *data, t_img *img, char *arg);
int		save_rgb(t_data *data, int *rgb_arr, char *arg);
void	exit_message(char *msg, int *fd);
int		check_nbr(char *str);
int		check_map_extension(char *map_name);
int		get_map_height(t_data *data);
int		get_size_line(char *line);

#endif