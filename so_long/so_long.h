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
#define PIXELPERFECT 64
#define CHARAC "./sprite/amongus.xpm"
#define RCHARAC "./sprite/ramongus.xpm"
#define EXIT "./sprite/Exit.xpm"
#define WALL "./tiles/wall.xpm"
#define TILES "./tiles/tiles.xpm"
#define PET "./pet/Didine.xpm"

typedef	struct	s_data 
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	char	**map;
	t_img	*charac;
	t_img	*exit;
	t_img	*tiles;
	t_img	*wall;
	t_img	*rcharac;
	t_img	*pet;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
	int	pixel_lenght;
	int	Px;
	int	Py;
	int	sens;
	int	ResoX;
	int	ResoY;
	int	nb_conso;
	int	Pconso;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	texture_init(t_data *img);
void	show_map_in_pixel(t_data *img);
void	show_tiles(t_data *img, int xmap, int ymap);
void	show_wall(t_data *img, int xmap, int ymap);
void	show_charac(t_data *img, int xmap, int ymap);
void	show_exit(t_data *img, int xmap, int ymap);
void	show_pet(t_data *img, int xmap, int ymap);
void	vertical(t_data *img, int key);
void	horizontal(t_data *img, int key);
void	find_exit(t_data *img);
void	find_resolution(t_data *img);
int	movement(t_data *img, int key);
int	deal_key(int key, t_data *img);
int	checkwall(t_data *img, int key);
int	checkexit(t_data *img, int key);
int	howmanyconso(t_data *img);
char	**stock_map_ber(char **map, char *argv);
#endif
