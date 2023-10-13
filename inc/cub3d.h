/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharlot <acharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:06:15 by acharlot          #+#    #+#             */
/*   Updated: 2023/10/13 10:47:53 by acharlot         ###   ########.fr       */
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

# include <math.h>

/*-----------------------------------------------------------------------------
								STRUCTURES
-----------------------------------------------------------------------------*/

typedef struct s_data	t_data;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}			t_data;

#endif