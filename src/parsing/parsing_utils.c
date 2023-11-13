/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:10:24 by cpothin           #+#    #+#             */
/*   Updated: 2023/11/13 17:07:11 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_nbr(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

void	exit_message(char *msg, int *fd)
{
	ft_printf("%s", msg);
	close(*fd);
	exit(0);
}

int	save_img(t_data *data, t_img *img, char *arg)
{
	int		size;
	char	**args;

	args = ft_split(arg, ' ');
	size = IMG_SIZE;
	if (!args[1])
		return (0);
	if (access(args[1], F_OK) == -1)
	{
		ft_printf("Error:\n\t%s doesn't exist\n", args[1]);
		return (0);
	}
	img->name = args[1];
	img->img = mlx_xpm_file_to_image(data->mlx, args[1], &size, &size);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
			&img->endian);
	if (!img->addr)
		panic(data, "Failure while getting the address of the image.");
	return (1);
}

int	save_rgb(t_data *data, int *rgb_arr, char *arg)
{
	char	**args;
	char	**nbrs;

	args = ft_split(arg, ' ');
	if (!args[1])
		return (0);
	nbrs = ft_split(args[1], ',');
	if (!check_nbr(nbrs[0]) || !check_nbr(nbrs[1]) || !check_nbr(nbrs[2]))
		return (0);
	rgb_arr[0] = ft_atoi(nbrs[0]);
	rgb_arr[1] = ft_atoi(nbrs[1]);
	rgb_arr[2] = ft_atoi(nbrs[2]);
	if (rgb_arr[0] < 0 || rgb_arr[0] > 255
		|| rgb_arr[1] < 0 || rgb_arr[1] > 255
		|| rgb_arr[2] < 0 || rgb_arr[2] > 255)
		return (0);
	return (1);
}

int	check_map_extension(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (map_name[i - 4] != '.' || map_name[i - 3] != 'c'
		|| map_name[i - 2] != 'u' || map_name[i - 1] != 'b')
		return (0);
	return (1);
}
