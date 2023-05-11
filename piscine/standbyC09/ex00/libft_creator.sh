# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 14:10:09 by mbatteux          #+#    #+#              #
#    Updated: 2023/02/01 14:10:11 by mbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

gcc -c ft_putchar.c
gcc -c ft_swap.c
gcc -c ft_putstr.c
gcc -c ft_strlen.c
gcc -c ft_strcmp.c

ar rc libft.a ft_strcmp.o ft_strlen.o ft_putstr.o ft_swap.o ft_putchar.o
