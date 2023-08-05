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
#include "./ft_printf/ft_printf.h"

int	deal_key(int key, t_data *img)
{
	if (key == ESC)
		oppenheimer(img);
	else if (key == UP || key == DOWN)
		movement(img, key);
	else if (key == LEFT || key == RIGHT)
		movement(img, key);
	return (0);
}

int	movement(t_data *img, int key)
{
	static int	counter = 1;

	if (key == LEFT || key == RIGHT)
	{
		if (checkwall(img, key) == 0 && checkexit_hor(img, key) == 0)
		{
			horizontal(img, key);
			ft_printf("Mouvements = %d\n", counter++);
		}
	}
	else if (key == UP || key == DOWN)
	{
		if (checkwall(img, key) == 0 && checkexit_ver(img, key) == 0)
		{
			vertical(img, key);
			ft_printf("Mouvements = %d\n", counter++);
		}
	}
	if (find_exit(img) == 1)
		oppenheimer(img);
	return (0);
}

void	vertical(t_data *img, int key)
{
	if (key == UP)
	{
		if (img->map[img->py - 1][img->px] == 'C')
			img->pconso += 1;
		img->map[img->py][img->px] = '0';
		img->map[--(img->py)][img->px] = 'P';
	}
	else if (key == DOWN)
	{
		if (img->map[img->py + 1][img->px] == 'C')
			img->pconso += 1;
		img->map[img->py][img->px] = '0';
		img->map[++(img->py)][img->px] = 'P';
	}
	show_map_in_pixel(img);
}

void	horizontal(t_data *img, int key)
{
	if (key == LEFT)
	{
		if (img->sens == LEFT)
		{
			if (img->map[img->py][img->px - 1] == 'C')
				img->pconso += 1;
			img->map[img->py][img->px] = '0';
			img->map[img->py][--(img->px)] = 'P';
		}
		else
			img->sens = LEFT;
	}
	else if (key == RIGHT)
	{	
		if (img->sens == RIGHT)
		{
			if (img->map[img->py][img->px + 1] == 'C')
				img->pconso += 1;
			img->map[img->py][img->px] = '0';
			img->map[img->py][++(img->px)] = 'P';
		}
		else
			img->sens = RIGHT;
	}
	show_map_in_pixel(img);
}

int	checkwall(t_data *img, int key)
{
	if (key == UP)
		if (img->map[img->py - 1][img->px] == '1')
			return (1);
	if (key == DOWN)
		if (img->map[img->py + 1][img->px] == '1')
			return (1);
	if (key == RIGHT)
	{
		if (img->map[img->py][img->px + 1] == '1')
		{
			img->sens = RIGHT;
			show_map_in_pixel(img);
			return (1);
		}
	}
	if (key == LEFT)
	{
		if (img->map[img->py][img->px - 1] == '1')
		{
			img->sens = LEFT;
			show_map_in_pixel(img);
			return (1);
		}
	}
	return (0);
}
