/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:17:36 by acharlot          #+#    #+#             */
/*   Updated: 2023/11/08 14:25:58 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_cub3d(t_data *data)
{
	data->file_content = NULL;
	data->img = init_img();
	data->player.movement.y = 0;
	data->player.movement.x = 0;
}
