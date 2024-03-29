/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:57:08 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/18 13:57:09 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	find_resolution(t_data *img)
{
	img->resox = 0;
	img->resoy = 0;
	while (img->map[img->resoy][img->resox])
		(img->resox)++;
	while (img->map[img->resoy])
		(img->resoy)++;
	if (img->resoy > 15 || img->resox > 30)
		return (1);
	img->resox = (img->resox - 1) * P;
	img->resoy = (img->resoy) * P;
	return (0);
}

char	**stock_map_ber(char **map, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		map[i++] = get_next_line(fd);
		if (map[i - 1] == NULL)
			break ;
	}
	return (map);
}

void	show_map_in_pixel(t_data *img)
{
	img->xmap = 0;
	img->ymap = 0;
	while (img->map[img->ymap] != NULL)
	{
		if (img->map[img->ymap][img->xmap] == '0')
			show_tiles(img);
		else if (img->map[img->ymap][img->xmap] == '1')
			show_wall(img);
		else if (img->map[img->ymap][img->xmap] == 'P')
			show_charac(img);
		else if (img->map[img->ymap][img->xmap] == 'E')
			show_exit(img);
		else if (img->map[img->ymap][img->xmap] == 'C')
			show_pet(img);
		(img->xmap)++;
		if (img->map[img->ymap][img->xmap] == '\0')
		{
			img->xmap = 0;
			(img->ymap)++;
		}
	}
}
