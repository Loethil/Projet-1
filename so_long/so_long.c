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

void	find_exit(t_data *img)
{
	int	i = 0;
	int	j = 0;
	int	e = 0;
	while(img->map[i] != NULL)
	{
		if (img->map[i][j] == 'E')
			e = 1;
		else if (img->map[i][j] == 0)
		{
			j = 0;
			i++;
		}
		j++;
	}
	if (e == 0)
		exit (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		img.map = malloc(10000000 * sizeof(char *));
		img.mlx = mlx_init();
		find_resolution(&img);
		// printf("%d", img.ResoX);
		// printf("%d", img.ResoY);
		img.win_ptr = mlx_new_window(img.mlx, /*(img.ResoX * 80)*/1840, /*(img.ResoY * 80)*/960, "so_long");
		img.img = mlx_new_image(img.mlx, /*(img.ResoX * 80)*/1840, /*(img.ResoY * 80)*/960);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
							&img.endian);
		img.map = stock_map_ber(img.map, argv[1]);
		show_map_in_pixel(&img);
		mlx_hook(img.win_ptr, 2, 1, deal_key, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
