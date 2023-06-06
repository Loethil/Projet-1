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

int	new_line(char *buf)
{
	int	r;

	r = 0;
	while (buf[r] != '\0')
	{
		if (buf[r] == '\n')
			return (1);
		r++;
	}
	return (0);
}

char	*check_pile(char *line, char *tmp)
{
	int	a;

	a = 0;
	//printf ("tmp = %s\n", tmp);
	if (tmp && tmp[a])
	{
		while (tmp[a])
		{
			line[a] = tmp[a];
			if (tmp[a] == '\0')
				free (tmp);
			a++;
		}
		line[a] = '\0';
	}
	return (line);
}

char	*change_line(char *line)
{
	int	v;

	v = 0;
	while (line[v] != '\n')
		v++;
	line[++v] = '\0';
	//printf("tmp = %s", tmp);
	return (line);
}

char	*create_pile(char *line, char *tmp)
{
	int	v;
	int	e;

	e = 0;
	v = 0;
	tmp = malloc (10000000 * sizeof(char));
	if (!tmp)
		return (NULL);
	while (line[v] != '\n')
		v++;
	while (line[++v] != '\0')
		tmp[e++] = line[v];
	tmp[e] = '\0';
	return (tmp);
}

char	*create_line(char *line, char *buf, char **tmp)
{
	int			r;
	int			a;

	r = 0;
	a = 0;
	//printf(" 89 tmp = %s", tmp);
	line = check_pile(line, *tmp);
	while (line[a])
		a++;
	while (buf[r])
		line[a++] = buf[r++];
	line[a] = '\0';
	if (new_line(line) == 1)
	{
		*tmp = create_pile(line, *tmp);
		line = change_line(line);
	}
	//printf("100 line = %s\n\n", line);
	//printf("TMP = %s\n", tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char	*line;
	char	buf[BUFFER_SIZE + 1];
	int		red;

	red = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	line = malloc(10000000 * sizeof(char));
	if (!line)
		return (NULL);
	while (red != 0)
	{
		if (new_line(line) == 1)
			return (line);
		red = read(fd, buf, BUFFER_SIZE);
		if (new_line(buf) == 1)
		{
			line = create_line(line, buf, &tmp);
			break ;
		}
		else if (new_line(buf) == 0)
			line = create_line(line, buf, &tmp);
		//printf("tmp = %s", tmp);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	//char	*gob;

	//gob = malloc(10000000 * sizeof(char));
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		/*while (gob != NULL)
		{
			gob = get_next_line(fd);
			printf ("%s", gob);
		}
		free (gob);*/
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
		printf ("%s", get_next_line(fd));
	}
	return (0);
}
