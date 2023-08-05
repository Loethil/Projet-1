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

# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115
# define ESC 65307
# define P 64
# define CHARAC "./sprite/amongus.xpm"
# define RCHARAC "./sprite/ramongus.xpm"
# define EXIT "./sprite/Exit.xpm"
# define WALL "./tiles/wall.xpm"
# define TILES "./tiles/tiles.xpm"
# define PET1 "./pet/petain.xpm"
# define PET2 "./pet/cousoupe.xpm"
# define PET3 "./pet/Didine.xpm"
# define PET4 "./pet/Francine.xpm"
# define PET5 "./pet/groscon.xpm"
# define PET6 "./pet/kiki.xpm"
# define PET7 "./pet/Michel.xpm"
# define PET8 "./pet/ptitecrotte.xpm"
# define PET9 "./pet/ptitmogus.xpm"
# define PET10 "./pet/Xavier.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
	void	*img;
	char	*addr;
	char	**map;
	char	**mapcopy;
	t_img	*charac;
	t_img	*exit;
	t_img	*tiles;
	t_img	*wall;
	t_img	*rcharac;
	t_img	*pets[10];
	int		intsansetoile;
	int		xmap;
	int		ymap;
	int		fd;
	int		pixel_lenght;
	int		px;
	int		py;
	int		sens;
	int		resox;
	int		resoy;
	int		sizex;
	int		sizey;
	int		nb_conso;
	int		pconso;
	int		conso;
	int		ifexit;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	texture_init(t_data *img);
void	show_map_in_pixel(t_data *img);
void	show_tiles(t_data *img);
void	show_wall(t_data *img);
void	show_charac(t_data *img);
void	show_exit(t_data *img);
void	show_pet(t_data *img);
void	vertical(t_data *img, int key);
void	horizontal(t_data *img, int key);
void	find_map_size(t_data *img);
void	petsinit(t_data *img);
void	freetab(char **tab);
int		find_resolution(t_data *img);
int		find_exit(t_data *img);
int		checkcharac(t_data *img);
int		check_error(t_data *img, char *argv);
int		check_error2(t_data *img, char *argv);
int		check_error3(t_data *img, char *argv);
int		movement(t_data *img, int key);
int		deal_key(int key, t_data *img);
int		checkwall(t_data *img, int key);
int		checkexit_ver(t_data *img, int key);
int		checkexit_hor(t_data *img, int key);
int		checkperimeter(t_data *img);
int		howmanyconso(t_data *img);
int		lee_algorithm(t_data *img);
int		check(t_data *img, int num, int x, int y);
int		checkvariable(t_data *img, int num, int x, int y);
int		oppenheimer(t_data *img);
char	**modified_map(t_data *img, int num, int *count);
char	**stock_map_ber(char **map, int fd);
#endif
