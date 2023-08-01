/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:46 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/28 11:15:47 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	find_exit(t_data *img)
{
	int	y;
	int	x;
	int	e;

	y = 0;
	x = 0;
	e = 0;
	while (img->map[y] != NULL)
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
		return (1);
	else
		return (0);
}

int	checkexit_ver(t_data *img, int key)
{
	if (img->Pconso != img->nb_conso)
	{
		if (key == UP)
			if (img->map[img->Py - 1][img->Px] == 'E')
				return (1);
		if (key == DOWN)
			if (img->map[img->Py + 1][img->Px] == 'E')
				return (1);
	}
	return (0);
}

int	checkexit_hor(t_data *img, int key)
{
	if (img->Pconso != img->nb_conso)
	{
		if (key == RIGHT)
		{
			if (img->map[img->Py][img->Px + 1] == 'E')
			{
				img->sens = RIGHT;
				show_map_in_pixel(img);
				return (1);
			}
		}
		if (key == LEFT)
		{
			if (img->map[img->Py][img->Px - 1] == 'E')
			{
				img->sens = LEFT;
				show_map_in_pixel(img);
				return (1);
			}
		}
	}
	return (0);
}
