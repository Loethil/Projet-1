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

typedef	struct	s_data 
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	char	**map;
	t_img	*charac;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
	int	pixel_lenght;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	show_square(t_data *img, int lon, int lar, char **firstlinemap);
void	show_map_in_pixel(char **map, t_data *img);
char	**stock_map_ber(char **map, char *argv);
int	escape(int key);
int	find_pixel_lenght(char **line);
void	show_people(t_data img, int larg, int lon);
#endif
