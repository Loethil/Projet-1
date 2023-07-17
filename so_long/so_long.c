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
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_data {

	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	char	**map;
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

int	escape(int key)
{
	printf ("touche = %d\n", key);
	if (key == 65307)
		exit (0);
	// mlx_put_image_to_window(img->mlx, img->win_ptr, img->img, 0, 0);
	return (0);
}

int	find_pixel_lenght(char **line)
{
	int	linelen;
	int	howmanyline;

	linelen = 0;
	howmanyline =0;
	while (line[howmanyline][linelen])
		linelen++;
	while (line[howmanyline])
		howmanyline++;
	if (linelen > howmanyline)
		return (480 / howmanyline);
	return (640 / linelen);
}
char	**stock_map_ber(char **map, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		map[i++] = get_next_line(fd);
		if (map[i - 1] == NULL)
			break ;
	}
	return (map);
}

void	show_square(t_data *img, int lon, int lar, char **firstlinemap)
{
	int	cubex;
	int	cubey;
	int	pixel_lenght;
	
	cubex = 0;
	cubey = 0;
	pixel_lenght = find_pixel_lenght(firstlinemap);
	while (cubey < pixel_lenght)
	{	
		while (cubex < pixel_lenght)
		{
			my_mlx_pixel_put(img, lon, lar, 0x00FFFFFF);
			cubex++;
			lon++;
		}
		lar++;
		lon -= cubex;
		cubex = 0;
		cubey++;
	}
}

void	show_map_in_pixel(char **map, t_data *img)
{
	int	lon = 0;
	int	lar = 0;
	int	xmap = 0;
	int	ymap = 0;

	while (map[ymap] != NULL)
	{
		if (map[ymap][xmap] == '1')
			show_square(img, lon, lar, map);
		lon += find_pixel_lenght(map);
		xmap++;
		if (map[ymap][xmap] == '\0')
		{
			lon = 0;
			xmap = 0;
			lar += find_pixel_lenght(map);
			ymap++;
		}
	}
	mlx_put_image_to_window(img->mlx, img->win_ptr, img->img, 0, 0);	
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
		mlx_put_image_to_window(img.mlx, img.win_ptr, img.img, 0, 0);
		img.map = stock_map_ber(img.map, argv[1]);
		show_map_in_pixel(img.map, &img);
		mlx_hook(img.win_ptr, 2, 1, escape, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
