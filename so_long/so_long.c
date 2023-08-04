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
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "./ft_printf/ft_printf.h"

int	check_error(t_data *img, char *argv)
{
	img->fd = open(argv, O_RDONLY);
	if (img->fd == -1)
	{
		ft_printf("Error\nMAP INTROUVABLE\n");
		return (1);
	}
	img->map = malloc((12 * 24) + 1 * sizeof(char *));
	if (!img->map)
		return (0);
	img->map = stock_map_ber(img->map, img->fd);
	close(img->fd);
	find_resolution(img);
	if (checkperimeter(img) == 1)
	{
		ft_printf("ERROR\nMAP INVALIDE\n");
		return (1);
	}
	if (howmanyconso(img) < 1)
	{
		ft_printf("ERROR\nPAS ASSEZ DE CONSOMMABLE\n");
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
		ft_printf("ERROR\nPAS DE SORTIE \n");
		return (1);
	}
	if (checkcharac(img) == 1)
	{
		ft_printf("ERROR\nPAS OU TROP DE PLAYER\n");
		return (1);
	}
	if (check_error3(img, argv) == 1)
		return (1);
	return (0);
}

int	check_error3(t_data *img, char *argv)
{
	img->fd = open(argv, O_RDONLY);
	img->mapcopy = malloc((12 * 24) + 1 * sizeof(char *));
	if (!img->mapcopy)
		return (0);
	img->mapcopy = stock_map_ber(img->mapcopy, img->fd);
	if (lee_algorithm(img) == 1)
	{
		ft_printf("Error\nCONSO OU SORTIE INACESSIBLE\n");
		freetab(img->mapcopy);
		return (1);
	}
	return (0);
}

int	oppenheimer(t_data *img)
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
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	img.map = NULL;
	srand(time(NULL));
	img.intsansetoile = rand() % 10;
	if (argc == 2)
	{
		if (check_error(&img, argv[1]) == 1)
		{
			freetab(img.map);
			return (0);
		}
		img.mlx = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx, img.ResoX, img.ResoY, "so_long");
		texture_init(&img);
		show_map_in_pixel(&img);
		mlx_hook(img.win_ptr, 17, 0, oppenheimer, &img);
		mlx_hook(img.win_ptr, 2, 1, deal_key, &img);
		mlx_loop(img.mlx);
	}
	else if (argc < 2 || argc > 2)
		ft_printf("Error\nDemasiados o insuficientes argumentos\n");
	return (0);
}
