/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mywayorthehighway.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:04:14 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/02 15:04:15 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int	check(t_data *img, int num, int x, int y)
{
	if (y - 1 >= 0 && img->mapcopy[y - 1][x] == num + 48)
		return (1);
	if (y < img->sizey - 1 && img->mapcopy[y + 1][x] == num + 48)
		return (1);
	if (x < img->sizex - 1 && img->mapcopy[y][x + 1] == num + 48)
		return (1);
	if (x - 1 >= 0 && img->mapcopy[y][x - 1] == num + 48)
		return (1);
	return (0);
}

int	checkvariable(t_data *img, int num, int x, int y)
{
	if (check(img, num, x, y) && img->mapcopy[y][x] == '0')
	{
		img->mapcopy[y][x] = num + 48;
		return (1);
	}
	if (check(img, num, x, y) && img->mapcopy[y][x] == 'C')
	{
		img->mapcopy[y][x] = num + 48;
		img->conso += 1;
		return (1);
	}
	if (check(img, num, x, y) && img->mapcopy[y][x] == 'E')
		img->ifexit = 1;
	return (0);
}

char	**modified_map(t_data *img, int num, int *count)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < img->sizey)
	{
		while (x < img->sizex)
		{
			if (checkvariable(img, num, x, y) == 1)
				(*count)++;
			x++;
		}
		x = 0;
		y++;
	}
	return (img->mapcopy);
}

int	lee_algorithm(t_data *img)
{
	int	num;
	int	count;

	num = 3;
	count = 0;
	img->mapcopy[img->py][img->px] = '3';
	img->conso = 0;
	img->ifexit = 0;
	while (1)
	{
		count = 0;
		img->mapcopy = modified_map(img, num, &count);
		if (!count)
			break ;
	}
	if (img->ifexit != 1 || img->conso != img->nb_conso)
		return (1);
	return (0);
}
