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
#include <stdio.h>
#include <stdlib.h>

int	howmanyconso(t_data *img)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	img->nb_conso = 0;
	img->pconso = 0;
	while (img->map[y] != NULL)
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
	return (img->nb_conso);
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

void	texture_init(t_data *img)
{
	int	width;
	int	height;

	petsinit(img);
	img->sens = LEFT;
	img->charac = mlx_xpm_file_to_image(img->mlx, CHARAC, &width, &height);
	img->rcharac = mlx_xpm_file_to_image(img->mlx, RCHARAC, &width, &height);
	img->exit = mlx_xpm_file_to_image(img->mlx, EXIT, &width, &height);
	img->wall = mlx_xpm_file_to_image(img->mlx, WALL, &width, &height);
	img->tiles = mlx_xpm_file_to_image(img->mlx, TILES, &width, &height);
}
