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

typedef	struct	s_data {

	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*win_ptr;
	t_data	img;
	int	x;
	int	y;

	x = 5;
	y = 5;
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
						&img.endian);
	while (x < 200 && y < 200)
		my_mlx_pixel_put(&img, x++, y++, 0x00FF0000);
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}