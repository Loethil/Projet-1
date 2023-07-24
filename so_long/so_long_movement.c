/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:56:38 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/20 14:56:39 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	deal_key(int key, t_data *img)
{
	printf ("touche = %d\n", key);
	if (key == ESC)
		exit (0);
	else if (key == UP || key == DOWN)
		movement(img, key);
	else if (key == LEFT || key == RIGHT)
		movement(img, key);
	return (0);
}

int	movement(t_data *img, int key)
{
	if (key == LEFT || key == RIGHT)
	{
		if (checkwall(img, key) == 0)
			horizontal(img, key);
		else
			return (0);
	}
	else if (key == UP || key == DOWN)
	{
		if (checkwall(img, key) == 0)
			vertical(img, key);
		else
			return (0);
	}
	find_exit(img);
	return (0);
}

void	vertical(t_data *img, int key)
{
	if (key == UP)
	{
		img->map[img->Py][img->Px] = '0';
		img->map[--(img->Py)][img->Px] = 'P';
	}
	else if (key == DOWN)
	{
		img->map[img->Py][img->Px] = '0';
		img->map[++(img->Py)][img->Px] = 'P';
	}
	show_map_in_pixel(img);
}

void	horizontal(t_data *img, int key)
{
	if (key == LEFT)
	{
		img->map[img->Py][img->Px] = '0';
		img->map[img->Py][--(img->Px)] = 'P';
	}
	else if (key == RIGHT)
	{
		img->map[img->Py][img->Px] = '0';
		img->map[img->Py][++(img->Px)] = 'P';
	}
	show_map_in_pixel(img);
}

int	checkwall(t_data *img, int key)
{
	if (key == UP)
		if (img->map[img->Py - 1][img->Px] == '1')
			return (1);
	if (key == DOWN)
		if (img->map[img->Py + 1][img->Px] == '1')
			return (1);
	if (key == RIGHT)
		if (img->map[img->Py][img->Px + 1] == '1')
			return (1);
	if (key == LEFT)
		if (img->map[img->Py][img->Px - 1] == '1')
			return (1);
	return (0);
}
