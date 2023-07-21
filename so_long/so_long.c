/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:34:19 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/17 15:34:20 by mbatteux         ###   ########.fr       */
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

int	deal_key(int key, t_data *img)
{
	printf ("touche = %d\n", key);
	if (key == ESC)
		exit (0);
	else if (key == UP || key == DOWN)
		movement(img, key);
	else if (key == LEFT || key == RIGHT)
		movement(img, key);
	return (0);
}

void	show_people(t_data *img)
{
	char	*people;
	int	img_larg;
	int	img_long;

	people = "./Idle.xpm";
	img->charac = mlx_xpm_file_to_image(img->mlx, people, &img_larg, &img_long);
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->charac, (img->Px * img->pixel_lenght) /*+ img->pixel_lenght / 2*/, (img->Py * img->pixel_lenght) /*+ img->pixel_lenght / 2*/);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		img.map = malloc(10000000 * sizeof(char *));
		img.mlx = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx, 1920, 1080, "so_long");
		img.img = mlx_new_image(img.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
							&img.endian);
		img.map = stock_map_ber(img.map, argv[1]);
		show_map_in_pixel(&img);
		mlx_hook(img.win_ptr, 2, 1, deal_key, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
