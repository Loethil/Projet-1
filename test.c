/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:17:53 by mbatteux          #+#    #+#             */
/*   Updated: 2023/06/19 16:17:54 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_data {

	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// printf("coucou");
	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_line(int key, t_data *img)
{
	static int	x = 10;
	static int	y = 10;

	printf ("touche = %d\n", key);
	if (key == 119)
		my_mlx_pixel_put(img, x, --y, 0x0000FF00);
	else if (key == 97)
		my_mlx_pixel_put(img, --x, y, 0x0000FF00);
	else if (key == 115)
		my_mlx_pixel_put(img, x, ++y, 0x0000FF00);
	else if (key == 100)
		my_mlx_pixel_put(img, ++x, y, 0x0000FF00);
	else if (key == 65307)
		exit (0);
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->img, 0, 0);
	return (0);
}
int	main(void)
{
	t_data	img;
	int	x;
	int	y;

	x = 5;
	y = 5;
	img.mlx = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
						&img.endian);
	mlx_put_image_to_window(img.mlx, img.win_ptr, img.img, 0, 0);
	// my_mlx_pixel_put(&img, x, y, 0x0000FF00);
	mlx_hook(img.win_ptr, 2, 1, draw_line, &img);
	// mlx_loop_hook(mlx, draw_line, &img);
	mlx_loop(img.mlx);
	return (0);
}