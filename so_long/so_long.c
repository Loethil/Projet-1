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

int	check_error(t_data *img, char *argv)
{
	img->map = malloc((12 * 24) + 1 * sizeof(char *));
	if (!img->map)
		return (0);
	img->map = stock_map_ber(img->map, argv);
	if (checkperimeter(img) == 1)
	{
		printf("ERROR\nMAP INVALIDE\n");
		freetab(img->map);
		return (1);
	}
	if (howmanyconso(img) < 1)
	{
		printf("ERROR\nPAS ASSEZ DE CONSOMMABLE\n");
		freetab(img->map);
		return (1);
	}
	if (check_error2(img, argv) == 1)
		return (1);
	return (0);
}

int	check_error2(t_data *img, char *argv)
{
	if (find_exit(img) == 1)
	{
		printf("ERROR\nPAS DE SORTIE \n");
		freetab(img->map);
		return (1);
	}
	if (checkcharac(img) == 1)
	{
		printf("ERROR\nPAS DE PLAYER\n");
		freetab(img->map);
		return (1);
	}
	if (find_resolution(img) == 1)
	{
		printf("ERROR\nLA MAP EST CARRE\n");
		freetab(img->map);
		return (1);
	}
	if (check_error3(img, argv) == 1)
	{
		freetab(img->map);
		return (1);
	}
	return (0);
}

int	check_error3(t_data *img, char *argv)
{
	img->mapcopy = malloc((12 * 24) + 1 * sizeof(char *));
	if (!img->mapcopy)
		return (0);
	img->mapcopy = stock_map_ber(img->mapcopy, argv);
	if (lee_algorithm(img) == 1)
	{
		printf("Error\nConso / sortie inaccessible\n");
		freetab(img->map);
		freetab(img->mapcopy);
		return (1);
	}
	return (0);
}

int	destroytheworld(t_data *img)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(img->mlx, img->pets[i++]);
	}
	mlx_destroy_image(img->mlx, img->charac);
	mlx_destroy_image(img->mlx, img->exit);
	mlx_destroy_image(img->mlx, img->tiles);
	mlx_destroy_image(img->mlx, img->wall);
	mlx_destroy_image(img->mlx, img->rcharac);
	mlx_destroy_window(img->mlx, img->win_ptr);
	mlx_destroy_display(img->mlx);
	freetab(img->map);
	freetab(img->mapcopy);
	free (img->mlx);
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
		texture_init(&img);
		show_map_in_pixel(&img);
		mlx_hook(img.win_ptr, 2, 1, deal_key, &img);
		mlx_loop(img.mlx);
	}
	else if (argc < 2 || argc > 2)
	{
		printf("Error\nDemasiados o insuficientes argumentos\n");
		return (0);
	}
	return (0);
}
