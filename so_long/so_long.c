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

int	main(int argc, char **argv)
{
	t_data	img;

	srand(time(NULL));
	if (argc == 2)
	{
		img.map = malloc(10000000 * sizeof(char *));
		img.map = stock_map_ber(img.map, argv[1]);
		find_resolution(&img);
		img.mlx = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx, img.ResoX, img.ResoY, "so_long");
		img.img = mlx_new_image(img.mlx, img.ResoX, img.ResoY);
		howmanyconso(&img);
		texture_init(&img);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
							&img.endian);
		show_map_in_pixel(&img);
		mlx_hook(img.win_ptr, 2, 1, deal_key, &img);
		mlx_loop(img.mlx);
		free(img.map);
	}
	return (0);
}
