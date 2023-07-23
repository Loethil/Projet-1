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
	// printf("%d", img->ResoX);
	// printf("%d", img->ResoY);
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

void	show_square(t_data *img, int lon, int lar)
{
	int	cubex;
	int	cubey;
	
	cubex = 0;
	cubey = 0;
	img->pixel_lenght = 80;
	// printf("%d\n", img->pixel_lenght);
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

void	show_map_in_pixel(t_data *img)
{
	int	lon = 0;
	int	lar = 0;
	int	xmap = 0;
	int	ymap = 0;

	while (img->map[ymap] != NULL)
	{
		if (img->map[ymap][xmap] == '1')
			show_square(img, lon, lar);
		lon += 80;
		xmap++;
		if (img->map[ymap][xmap] == 'P')
		{
			img->Px = xmap;
			img->Py = ymap;
		}
		else if (img->map[ymap][xmap] == 'E')
		{
			img->Ex = xmap;
			img->Ey = ymap;
		}
		else if (img->map[ymap][xmap] == '\0')
		{
			lon = 0;
			xmap = 0;
			lar += 80;
			ymap++;
		}
	}
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->img, 0, 0);	
	show_charac(img);
	show_exit(img);
}