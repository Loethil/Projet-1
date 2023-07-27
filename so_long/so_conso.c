/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_conso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:47:36 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/26 14:47:37 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	howmanyconso(t_data *img)
{
	int	y = 0;
	int	x = 0;
	img->nb_conso = 0;
	img->Pconso = 0;
	while(img->map[y] != NULL)
	{
		if (img->map[y][x] == 'C')
			(img->nb_conso)++;
		else if (img->map[y][x] == 0)
		{
			x = 0;
			y++;
		}
		x++;
	}
	img->intetoile = malloc((img->nb_conso + 1) * sizeof(int));
	if (!img->intetoile)
		return ;
	x = 0;
	while (x < img->nb_conso)
		img->intetoile[x++] = rand() % 10;
}

void	petsinit(t_data *img)
{
	int	width;
	int	height;
	
	img->pets[0] = mlx_xpm_file_to_image(img->mlx, PET1, &width, &height);
	img->pets[1] = mlx_xpm_file_to_image(img->mlx, PET2, &width, &height);
	img->pets[2] = mlx_xpm_file_to_image(img->mlx, PET3, &width, &height);
	img->pets[3] = mlx_xpm_file_to_image(img->mlx, PET4, &width, &height);
	img->pets[4] = mlx_xpm_file_to_image(img->mlx, PET5, &width, &height);
	img->pets[5] = mlx_xpm_file_to_image(img->mlx, PET6, &width, &height);
	img->pets[6] = mlx_xpm_file_to_image(img->mlx, PET7, &width, &height);
	img->pets[7] = mlx_xpm_file_to_image(img->mlx, PET8, &width, &height);
	img->pets[8] = mlx_xpm_file_to_image(img->mlx, PET9, &width, &height);
	img->pets[9] = mlx_xpm_file_to_image(img->mlx, PET10, &width, &height);
}

void	find_exit(t_data *img)
{
	int	y = 0;
	int	x = 0;
	int	e = 0;
	while(img->map[y] != NULL)
	{
		if (img->map[y][x] == 'E')
			e = 1;
		if (img->map[y][x] == 0)
		{
			x = 0;
			y++;
		}
		x++;
	}
	if (e == 0)
		exit (0);
}

int	checkexit(t_data *img, int key)
{
	if (img->Pconso != img->nb_conso)
	{
		if (key == UP)
			if (img->map[img->Py - 1][img->Px] == 'E')
				return (1);
		if (key == DOWN)
			if (img->map[img->Py + 1][img->Px] == 'E')
				return (1);
		if (key == RIGHT)
			if (img->map[img->Py][img->Px + 1] == 'E')
			{
				img->sens = RIGHT;
				show_map_in_pixel(img);
				return (1);
			}
		if (key == LEFT)
			if (img->map[img->Py][img->Px - 1] == 'E')
			{
				img->sens = LEFT;
				show_map_in_pixel(img);
				return (1);
			}
	}
	return (0);
}