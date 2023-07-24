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

void	show_charac(t_data *img)
{
	char	*charac;
	int	img_larg;
	int	img_long;

	charac = "./sprite/Idle.xpm";
	img->charac = mlx_xpm_file_to_image(img->mlx, charac, &img_larg, &img_long);
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->charac, (img->Px * img->pixel_lenght) /*+ img->pixel_lenght / 2*/, (img->Py * img->pixel_lenght) /*+ img->pixel_lenght / 2*/);
}

void	show_exit(t_data *img)
{
	char	*exit;
	int	exit_larg;
	int	exit_long;

	exit = "./sprite/people.xpm";
	img->exit = mlx_xpm_file_to_image(img->mlx, exit, &exit_larg, &exit_long);
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->exit, (img->Ex * img->pixel_lenght), (img->Ey * img->pixel_lenght));
}
