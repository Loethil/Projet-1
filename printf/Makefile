# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 16:59:14 by mbatteux          #+#    #+#              #
#    Updated: 2023/05/02 16:59:16 by mbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME): fichier_o
	ar rc libftprintf.a ft_*.o
fichier_o:
	gcc -c ft_*.c $(FLAG)
clean:
	rm -rf ft_*.o
fclean: clean
	rm -rf libftprintf.a
re: fclean all
