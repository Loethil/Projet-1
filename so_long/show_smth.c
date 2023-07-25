/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_smth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:54:29 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/24 13:54:30 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	show_charac(t_data *img, int xmap, int ymap)
{
	img->Px = xmap;
	img->Py = ymap;
	if (img->sens == LEFT)
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->rcharac, (xmap * PIXELPERFECT), (ymap * PIXELPERFECT));
	else if (img->sens == RIGHT)
		mlx_put_image_to_window(img->mlx, img->win_ptr, img->charac, (xmap * PIXELPERFECT), (ymap * PIXELPERFECT));
}

void	show_exit(t_data *img, int xmap, int ymap)
{
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->exit, (xmap * PIXELPERFECT), (ymap * PIXELPERFECT));
}

void	show_wall(t_data *img, int xmap, int ymap)
{
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->wall, (xmap * PIXELPERFECT), (ymap * PIXELPERFECT));
}

void	show_tiles(t_data *img, int xmap, int ymap)
{
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->tiles, (xmap * PIXELPERFECT), (ymap * PIXELPERFECT));
}
void	show_pet(t_data *img, int xmap, int ymap)
{
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->pet, (xmap * PIXELPERFECT), (ymap * PIXELPERFECT));
}