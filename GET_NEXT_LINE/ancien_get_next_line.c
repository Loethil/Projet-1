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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//permet de savoir si le buf contient un \n
int	new_line(char *buf)
{
	int	r;

	r = 0;
	while (buf[r])
	{	
		if (buf[r] == '\n')
			return (1);
		r++;
	}
	return (0);
}

//cree le tableau de chaine de caractere temporaire
char	*create_pile(char *line, char *buf)
{
	static char *tmp;
	int	v;
	int	a;

	v = -1;
	a = 0;
	tmp = malloc((ft_strlen(buf)) * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	while (buf[++v])
		tmp[v] = buf[v];
	while (line[a])
		a++;
	v = 0;
	while (tmp[v] != '\n')
		line[a++] = tmp[v++];
	line[++a] = '\n';
	line[++a] = '\0';
	return (line);
}
/*
//rajoute ce qui est stocke dans tmp au debut de line
char	*stock_pile(char *line, char *tmp)
{
	
}
*/
//construit et renvoie la ligne voulu.
char	*create_line(char *line, char *buf)
{
	int	a;
	int	v;

	a = 0;
	v = 0;
	while (line[a] != '\0')
		a++;
	while (buf[v] != '\0')
		line[a++] = buf[v++];
	line[++a] = '\0';
	return (line);
}

//fonction principale
char	*get_next_line(int fd)
{
	char	*line;
	char	buf[BUFFER_SIZE + 1];
	int	red;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	line = malloc(10000000 * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while ((red = read(fd, buf, BUFFER_SIZE)))
	{
		buf[red] = '\0';
		if (new_line(buf) == 1)
		{
			line = create_pile(line, buf);
			//printf ("%s\n", buf);
			break;
		}
		else
		{
			line = create_line(line, buf);
		}
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	//char	*gob;

	if(argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		//gob = get_next_line(fd);
		printf("%s\n", get_next_line(fd));
		//free(gob);
	}
}