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

int	ft_strlen(char	*tmp)
{
	int	l;

	l = 0;
	if (tmp == NULL)
		return (0);
	while (tmp[l])
		l++;
	return (l);
}

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
	if (ft_strlen(tmp) > 0)
	{
		while (tmp[a])
		{
			line[a] = tmp[a];
			a++;
		}
		line[a] = '\0';
		tmp[0] = '\0';
		free (tmp);
	}
	return (line);
}

char	*change_line(char *line, char *tmp)
{
	int	v;
	int	e;

	v = 0;
	e = 0;
	while (line[v] != '\n')
		v++;
	while (line[++v] != '\0')
		tmp[e++] = line[v];
	tmp[e] = '\0';
	v = 0;
	while (line[v] != '\n')
		v++;
	line[++v] = '\0';
	//printf ("tmp = %s\n", tmp);
	return (line);
}

char	*create_line(char *line, char *buf, int nbr)
{
	static char	*tmp;
	int			r;
	int			a;

	r = 0;
	a = 0;
	line = check_pile(line, tmp);
	while (line[a])
		a++;
	while (buf[r])
		line[a++] = buf[r++];
	line[a] = '\0';
	if (new_line(line) == 1)
	{
		tmp = malloc (nbr * sizeof(char) + 1);
		line = change_line(line, tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[BUFFER_SIZE];
	int		red;

	red = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	line = malloc(10000000 * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while (red != 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (new_line(buf) == 1)
		{
			line = create_line(line, buf, BUFFER_SIZE);
			break ;
		}
		else if (new_line(buf) == 0)
			line = create_line(line, buf, BUFFER_SIZE);
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
