/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ironic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:36:41 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/24 14:36:42 by mbatteux         ###   ########.fr       */
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
	char	buf[1];
	int	red;
	int	r;

	r = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	line = malloc(10000000 * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while ((red = read(fd, buf, (BUFFER_SIZE - BUFFER_SIZE) + 1)))
	{
		buf[red] = '\0';
		line[r++] = buf[0];
		if (buf[0] == '\n')
			break;
	}
	line[++r] = '\0';
	return (line);
}
/*
int	main(int argc, char **argv)
{
	int	fd;
	int	gub;
	char	*gob;

	gub = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		while (gub < 18)
		{
			gob = get_next_line(fd);
			printf("%s", gob);
			free(gob);
			gub++;
		}
	}
}
*/