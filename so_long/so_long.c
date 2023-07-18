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

int	escape(int key)
{
	printf ("touche = %d\n", key);
	if (key == 65307)
		exit (0);
	// mlx_put_image_to_window(img->mlx, img->win_ptr, img->img, 0, 0);
	return (0);
}

void	show_people(t_data img, int larg, int lon)
{
	char	*people;
	int	img_larg;
	int	img_long;

	people = "./people.xpm";
	img.charac = mlx_xpm_file_to_image(img.mlx, people, &img_larg, &img_long);
	mlx_put_image_to_window(img.mlx, img.win_ptr, img.charac, (larg * img.pixel_lenght) + img.pixel_lenght / 2, (lon * img.pixel_lenght) + img.pixel_lenght / 2);
}

int	main(int argc, char **argv)
{
	t_data	img;
	// char	*relative_path;
	// int	img_larg;
	// int	img_long;

	// relative_path = "./texture/mdf_1k_r.xpm";
	if (argc == 2)
	{
		img.map = malloc(10000000 * sizeof(char *));
		img.mlx = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx, 1920, 1080, "so_long");
		img.img = mlx_new_image(img.mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
							&img.endian);
		// img.img = mlx_xpm_file_to_image(img.mlx, relative_path, &img_larg, &img_long);
		img.map = stock_map_ber(img.map, argv[1]);
		show_map_in_pixel(img.map, &img);
		// show_people(img);
		mlx_hook(img.win_ptr, 2, 1, escape, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
