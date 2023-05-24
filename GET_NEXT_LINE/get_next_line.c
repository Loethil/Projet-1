/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:45:23 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/22 15:45:25 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//fonction principale
char	*get_next_line(int fd)
{
	char	*line;
	char	buf;
	int		red;
	int		r;

	r = 0;
	red = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buf, 0) < 0)
		return (NULL);
	line = malloc(10000000 * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while (red > 0)
	{
		red = read(fd, &buf, (BUFFER_SIZE - BUFFER_SIZE) + 1);
		line[r++] = buf;
		if (buf == '\n')
			break ;
	}
	line[r] = '\0';
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%s", get_next_line(fd));
	}
}
