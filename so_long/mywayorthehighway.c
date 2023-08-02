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
#include "./get_next_line/get_next_line.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int check(t_data *img, int num, int x, int y)
{
	// check up
	if (y - 1 >= 0 && img->mapcopy[y - 1][x] == num + 48)
		return 1;
	//check down
	if (y < img->sizeY - 1 && img->mapcopy[y + 1][x] == num + 48)
		return 1;
	// check right
	if (x < img->sizeX - 1 && img->mapcopy[y][x + 1] == num + 48)
		return 1;
	//check left
	if (x - 1 >= 0 && img->mapcopy[y][x - 1] == num + 48)
		return 1;
	return 0;
}

// create the wave into the tab (start to 3 and go on)
char	**modified_map(t_data *img, int num, int *count)
{
	int	y = 0;
	int	x = 0;
	y = 0;
	x = 0;
	while (y < img->sizeY)
	{
		while (x < img->sizeX)
		{
			if (check(img, num, x, y) && img->mapcopy[y][x] == '0')
			{
				img->mapcopy[y][x] = num + 48;
				(*count)++;
			}
			if (check(img, num, x, y) && img->mapcopy[y][x] == 'C')
			{
				img->mapcopy[y][x] = num + 48;
				img->conso += 1;
				(*count)++;
			}
			if (check(img, num, x, y) && img->mapcopy[y][x] == 'E')
			{
				img->mapcopy[y][x] = num + 48;
				img->ifexit = 1;
				(*count)++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (img->mapcopy);
}

int	lee_algorithm(t_data *img)
{
	int num = 3;
	int count = 0;
	img->mapcopy[img->Py][img->Px] = '3';
	img->conso = 0;
	img->exit = 0;
	while (1)
	{
		count = 0;
		img->mapcopy = modified_map(img, num, &count);
		if (!count)
			break;
	}
	if (img->ifexit == 0)
		return (1);
	if (img->conso != img->nb_conso)
		return (1);
	return(0);
}
		// for (int i = 0; img->mapcopy[i]; i++)
		// {
		// 	for(int j = 0; img->mapcopy[i][j]; j++)
		// 		printf("%c", img->mapcopy[i][j]);
		// }
	// img->map = malloc(10000000 * sizeof(char *));
	// if (!img->map)
	// 	return (0);
	// img->map = stock_map_ber(img->map, "./map/map.ber");
