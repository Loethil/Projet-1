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
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	check_error(t_data *img, char *argv)
{
	img->map = malloc(10000000 * sizeof(char *));
	if (!img->map)
		return (0);
	img->map = stock_map_ber(img->map, argv);
	if (checkperimeter(img) == 1)
	{
		printf("ERROR\nMAP INVALIDE");
		free(img->map);
		return (1);
	}
	if (howmanyconso(img) < 1)
	{
		printf("ERROR\nPAS ASSEZ DE CONSOMMABLE\n");
		free(img->map);
		return (1);
	}
	if (check_error2(img) == 1)
		return (1);
	return (0);
}

int	check_error2(t_data *img)
{
	if (find_exit(img) == 1)
	{
		printf("ERROR\nPAS DE SORTIE \n");
		free(img->map);
		return (1);
	}
	if (checkcharac(img) == 1)
	{
		printf("ERROR\nPAS DE PLAYER \n");
		free(img->map);
		return (1);
	}
	if (find_resolution(img) == 1)
	{
		printf("ERROR\nLA MAP EST CARRE \n");
		free(img->map);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	srand(time(NULL));
	if (argc == 2)
	{
		if (check_error(&img, argv[1]) == 1)
			return (0);
		img.mlx = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx, img.ResoX, img.ResoY, "so_long");
		img.img = mlx_new_image(img.mlx, img.ResoX, img.ResoY);
		texture_init(&img);
		img.addr = mlx_get_data_addr(img.img,
				&img.bits_per_pixel, &img.line_lenght, &img.endian);
		show_map_in_pixel(&img);
		mlx_hook(img.win_ptr, 2, 1, deal_key, &img);
		mlx_loop(img.mlx);
		free(img.map);
	}
	return (0);
}
