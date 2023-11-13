/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:00:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/13 17:03:19 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_line(t_data *data, char *line)
{
	if (!data->valid_args.no && line[0] == 'N'
		&& line[1] == 'O' && line[2] == ' ')
		data->valid_args.no = true;
	else if (!data->valid_args.so && line[0] == 'S'
		&& line[1] == 'O' && line[2] == ' ')
		data->valid_args.so = true;
	else if (!data->valid_args.we && line[0] == 'W'
		&& line[1] == 'E' && line[2] == ' ')
		data->valid_args.we = true;
	else if (!data->valid_args.ea && line[0] == 'E'
		&& line[1] == 'A' && line[2] == ' ')
		data->valid_args.ea = true;
	else if (!data->valid_args.f && line[0] == 'F' && line[1] == ' ')
		data->valid_args.f = true;
	else if (!data->valid_args.c && line[0] == 'C' && line[1] == ' ')
		data->valid_args.c = true;
	else
		return (0);
	return (1);
}

void	check_args_lines(t_data *data, char *lines[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!check_line(data, lines[i++]))
			data->valid_args.valid = false;
	}
	if (!data->valid_args.valid)
	{
		ft_printf("Error:\n\tThe file content is wrong\n");
		exit_game(data);
	}
}
