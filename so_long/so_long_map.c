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

int	find_pixel_lenght(char **line)
{
	int	linelen;
	int	howmanyline;

	linelen = 0;
	howmanyline =0;
	while (line[howmanyline][linelen])
		linelen++;
	while (line[howmanyline])
		howmanyline++;
	if (linelen > howmanyline)
		return (480 / howmanyline);
	return (640 / linelen);
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

void	show_square(t_data *img, int lon, int lar, char **firstlinemap)
{
	int	cubex;
	int	cubey;
	
	cubex = 0;
	cubey = 0;
	img->pixel_lenght = find_pixel_lenght(firstlinemap);
	while (cubey < img->pixel_lenght)
	{	
		while (cubex < img->pixel_lenght)
		{
			my_mlx_pixel_put(img, lon, lar, 0x00FFFFFF);
			cubex++;
			lon++;
		}
		lar++;
		lon -= cubex;
		cubex = 0;
		cubey++;
	}
}

void	show_map_in_pixel(char **map, t_data *img)
{
	int	lon = 0;
	int	lar = 0;
	int	xmap = 0;
	int	ymap = 0;
	int	p;
	int	e;

	while (map[ymap] != NULL)
	{
		if (map[ymap][xmap] == '1')
			show_square(img, lon, lar, map);
		lon += find_pixel_lenght(map);
		xmap++;
		if (map[ymap][xmap] == 'P')
		{
			e = xmap;
			p = ymap;
		}
		else if (map[ymap][xmap] == '\0')
		{
			lon = 0;
			xmap = 0;
			lar += find_pixel_lenght(map);
			ymap++;
		}
	}
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->img, 0, 0);	
	show_people(*img, e, p);
}