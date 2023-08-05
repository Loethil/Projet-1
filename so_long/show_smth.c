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
#include <stdio.h>
#include <stdlib.h>

void	show_charac(t_data *img)
{
	img->px = img->xmap;
	img->py = img->ymap;
	if (img->sens == LEFT)
		mlx_put_image_to_window(img->mlx,
			img->win_ptr, img->rcharac, (img->xmap * P), (img->ymap * P));
	else if (img->sens == RIGHT)
		mlx_put_image_to_window(img->mlx,
			img->win_ptr, img->charac, (img->xmap * P), (img->ymap * P));
}

void	show_exit(t_data *img)
{
	mlx_put_image_to_window(img->mlx,
		img->win_ptr, img->exit, (img->xmap * P), (img->ymap * P));
}

void	show_wall(t_data *img)
{
	mlx_put_image_to_window(img->mlx,
		img->win_ptr, img->wall, (img->xmap * P), (img->ymap * P));
}

void	show_tiles(t_data *img)
{
	mlx_put_image_to_window(img->mlx,
		img->win_ptr, img->tiles, (img->xmap * P), (img->ymap * P));
}

void	show_pet(t_data *img)
{
	mlx_put_image_to_window(img->mlx,
		img->win_ptr, img->pets[img->intsansetoile],
		(img->xmap * P), (img->ymap * P));
}
