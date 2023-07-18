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

OOO = so_long.o so_long_map.o

CCC = so_long.c so_long_map.c

FLAG = -Wall -Wextra -Werror

GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

LIBINCLUDE = -Lminilibx-linux -lmlx_Linux -I minilibx-linux -lXext -lX11

all: $(NAME)

$(NAME): .c.o
	gcc $(OOO) $(FLAG) $(GET_NEXT_LINE) $(LIBINCLUDE) -o $(NAME)
.c.o :
	gcc -c $(CCC) $(GET_NEXT_LINE) $(FLAG) $(LIBINCLUDE)
clean:
	rm -f $(OOO)
fclean: clean
	rm -f $(NAME)
re: fclean all
