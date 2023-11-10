/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:00:06 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/10 17:48:41 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	add_door(t_data *data, t_vector2 pos)
{
	t_door	*door;
	t_door	*head;

	door = gc_alloc(sizeof(t_door), "door");
	door->is_open = false;
	door->pos.x = pos.x;
	door->pos.y = pos.y;
	door->next = NULL;
	if (!data->doors)
	{
		data->doors = door;
		return ;
	}
	head = data->doors;
	while (head->next)
		head = head->next;
	head->next = door;
}

void	init_doors(t_data *data)
{
	t_vector2	pos;

	if (!BONUS)
		return ;
	data->doors = NULL;
	pos.y = 0;
	while (data->map_info.level[pos.y])
	{
		pos.x = 0;
		while (data->map_info.level[pos.y][pos.x])
		{
			if (data->map_info.level[pos.y][pos.x] == 'D')
			{
				add_door(data, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}
