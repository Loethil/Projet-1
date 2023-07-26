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

int	howmanyconso(t_data *img)
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
	return(img->nb_conso);
}

// void	find_exit(t_data *img)
// {
// 	int	y = 0;
// 	int	x = 0;
// 	int	e = 0;
// 	while(img->map[y] != NULL)
// 	{
// 		if (img->map[y][x] == 'E')
// 			e = 1;
// 		if (img->map[y][x] == 0)
// 		{
// 			x = 0;
// 			y++;
// 		}
// 		x++;
// 	}
// 	if (e == 0 && img->Pconso == img->nb_conso)
// 		exit (0);
// }

int	checkexit(t_data *img, int key)
{
	printf("%d\n", img->Pconso);
	printf("%d\n", img->nb_conso);
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