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

OOO = so_long.o so_long_map.o so_long_movement.o show_smth.o get_next_line_utils.o get_next_line.o

CCC = so_long.c so_long_map.c so_long_movement.c show_smth.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

FLAG = -Wall -Wextra -Werror

GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

LIBINCLUDE = -Lminilibx-linux -lmlx_Linux -I minilibx-linux -lXext -lX11

all: $(NAME)

$(NAME): .c.o
	gcc $(OOO) $(FLAG) $(LIBINCLUDE) -o $(NAME) -g3
.c.o :
	gcc -c $(CCC) $(FLAG) $(LIBINCLUDE) -g3
clean:
	rm -f $(OOO)
fclean: clean
	rm -f $(NAME)
re: fclean all
