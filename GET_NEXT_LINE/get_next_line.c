/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:13 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/10 15:27:14 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int	ret;
	static int	i = -1;
	i += 1;
	char	tab[BUFFER_SIZE + 1];
	char	*tub;

	ret = read(fd, tab, BUFFER_SIZE);
	tab[ret] = '\0';
	tub = malloc((ft_ligne(tab) * sizeof(char) + 1));
	while (tab[i] != '\n' && tab[i])
	{
		tub[i] = tab[i];
		i++;
	}
	tub[i] = '\0';
	return (tub);
}

int	main(int argc, char **argv)
{
	int	fd;

	if(argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
	}
}