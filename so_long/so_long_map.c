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

void	find_resolution(t_data *img)
{
	img->ResoX = 0;
	img->ResoY = 0;
	while (img->map[img->ResoY][img->ResoX])
		(img->ResoX)++;
	while (img->map[img->ResoY])
		(img->ResoY)++;
	img->ResoX = img->ResoX * PIXELPERFECT;
	img->ResoY = img->ResoY * PIXELPERFECT;
}

char	**stock_map_ber(char **map, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
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
	int	xmap = 0;
	int	ymap = 0;

	while (img->map[ymap] != NULL)
	{
		if (img->map[ymap][xmap] == '0')
			show_tiles(img, xmap, ymap);
		else if (img->map[ymap][xmap] == '1')
			show_wall(img, xmap, ymap);
		else if (img->map[ymap][xmap] == 'P')
			show_charac(img, xmap, ymap);
		else if (img->map[ymap][xmap] == 'E')
			show_exit(img ,xmap, ymap);
		xmap++;
		if (img->map[ymap][xmap] == '\0')
		{
			xmap = 0;
			ymap++;
		}
	}
}