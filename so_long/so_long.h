/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:43:18 by mbatteux          #+#    #+#             */
/*   Updated: 2023/07/18 15:43:19 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./get_next_line/get_next_line.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdio.h>
#include <stdlib.h>
#define LEFT 97
#define RIGHT 100
#define UP 119
#define DOWN 115
#define ESC 65307
#define PIXELPERFECT 80

typedef	struct	s_data 
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	char	**map;
	t_img	*charac;
	t_img	*exit;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
	int	pixel_lenght;
	int	Px;
	int	Py;
	int	Ex;
	int	Ey;
	int	ResoX;
	int	ResoY;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	show_square(t_data *img, int lon, int lar);
void	show_map_in_pixel(t_data *img);
void	show_charac(t_data *img);
void	show_exit(t_data *img);
void	vertical(t_data *img, int key);
void	horizontal(t_data *img, int key);
void	find_exit(t_data *img);
void	find_resolution(t_data *img);
int	movement(t_data *img, int key);
int	deal_key(int key, t_data *img);
int	checkwall(t_data *img, int key);
char	**stock_map_ber(char **map, char *argv);
#endif
