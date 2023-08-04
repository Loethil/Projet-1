# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 11:32:08 by mbatteux          #+#    #+#              #
#    Updated: 2023/07/17 11:32:10 by mbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CCC = ./get_next_line/get_next_line.c\
	./get_next_line/get_next_line_utils.c\
	mywayorthehighway.c\
	show_smth.c\
	so_exit.c\
	so_long_movement.c\
	so_conso.c\
	so_long.c\
	so_errors.c\
	so_long_map.c\
	ft_printf/ft_hexformat.c\
	ft_printf/ft_putadress.c\
	ft_printf/ft_puthex.c\
	ft_printf/ft_putnbrpos_fd.c\
	ft_printf/ft_pvoid.c\
	ft_printf/ft_printf.c\
	ft_printf/ft_putchar_fd.c\
	ft_printf/ft_putnbr_fd.c\
	ft_printf/ft_putstr_fd.c

OOO = $(CCC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBINCLUDE = -Lminilibx-linux -lmlx_Linux -I minilibx-linux -lXext -lX11

all: $(NAME)

$(NAME): $(OOO)
	gcc $(OOO) $(FLAG) $(LIBINCLUDE) -o $(NAME) -g3
.c.o:
	gcc $(FLAG) $(LIBINCLUDE)  -c $< -o ${<:.c=.o} -g3
clean:
	rm -f $(OOO)
fclean: clean
	rm -f $(NAME)
re: fclean all
