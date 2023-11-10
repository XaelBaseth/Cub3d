/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:00:06 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/10 19:01:13 by cpothin          ###   ########.fr       */
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

void	open_close_door(t_data *data, t_door *door)
{
	door->is_open = !door->is_open;
	if (door->is_open)
		data->map_info.level[door->pos.y][door->pos.x] = '0';
	else
		data->map_info.level[door->pos.y][door->pos.x] = 'D';
}

void	check_open_doors(t_data *data)
{
	t_door	*head;

	head = data->doors;
	while (head)
	{
		if (((int)data->player.pos_x == head->pos.x + 1
			|| (int)data->player.pos_x == head->pos.x - 1)
			&& ((int)data->player.pos_y == head->pos.y
			|| (int)data->player.pos_y == head->pos.y)
			|| ((int)data->player.pos_x == head->pos.x
			|| (int)data->player.pos_x == head->pos.x)
			&& ((int)data->player.pos_y == head->pos.y + 1
			|| (int)data->player.pos_y == head->pos.y - 1))
			open_close_door(data, head);
		head = head->next;
	}
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
