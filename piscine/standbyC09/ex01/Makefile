# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:16:16 by mbatteux          #+#    #+#              #
#    Updated: 2023/02/01 14:36:44 by mbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
all: libft.a

libft.a:
	gcc -c srcs/*.c -Wall -Wextra -Werror
	ar rc libft.a srcs/*.o
clean:
	rm -f *.o
fclean: clean
	rm -f *.a
