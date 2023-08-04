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
// #include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	find_map_size(t_data *img)
{
	img->sizex = 0;
	img->sizey = 0;
	while (img->map[img->sizey][img->sizex])
		(img->sizex)++;
	while (img->map[img->sizey])
		(img->sizey)++;
	img->sizex = img->sizex - 1;
	img->sizey = img->sizey;
}

int	checkcharac(t_data *img)
{
	int	p;

	p = 0;
	img->xmap = 0;
	img->ymap = 0;
	while (img->map[img->ymap] != NULL)
	{
		if (img->map[img->ymap][img->xmap] == 'P')
		{
			p += 1;
			break ;
		}
		if (img->map[img->ymap][img->xmap] == 0)
		{
			img->xmap = 0;
			(img->ymap)++;
		}
		(img->xmap)++;
	}
	if (p == 0 || p > 1)
		return (1);
	img->Px = img->xmap;
	img->Py = img->ymap;
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
	while (img->ymap < img->sizey - 1)
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

void	freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free (tab);
}
