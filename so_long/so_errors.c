/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:36:48 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/28 13:36:50 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	find_map_size(t_data *img)
{
	img->sizeX = 0;
	img->sizeY = 0;
	while (img->map[img->sizeY][img->sizeX])
		(img->sizeX)++;
	while (img->map[img->sizeY])
		(img->sizeY)++;
	img->sizeX = img->sizeX - 1;
	img->sizeY = img->sizeY;
}

int	checkcharac(t_data *img)
{
	int	y;
	int	x;
	int	p;

	y = 0;
	x = 0;
	p = 0;
	while (img->map[y] != NULL)
	{
		if (img->map[y][x] == 'P')
			p = 1;
		if (img->map[y][x] == 0)
		{
			x = 0;
			y++;
		}
		x++;
	}
	if (p == 0)
		return (1);
	else
		return (0);
}

int	checkperimeter(t_data *img)
{
	img->xmap = 0;
	img->ymap = 0;
	find_map_size(img);
	while (img->xmap < img->sizeX - 1)
		if (img->map[img->ymap][(img->xmap)++] != '1')
			return (1);
	while (img->ymap < img->sizeY - 1)
		if (img->map[(img->ymap)++][img->xmap] != '1')
			return (1);
	while (img->xmap > 0)
		if (img->map[img->ymap][(img->xmap)--] != '1')
			return (1);
	while (img->ymap > 0)
		if (img->map[(img->ymap)--][img->xmap] != '1')
			return (1);
	return (0);
}
