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
char	*create_pile(char *buf, char *tmp)
{
	int	v;
	int	j;

	v = 0;
	j = 0;
	while (buf[j] != '\n')
		j++;
	while (buf[++j])
		tmp[v++] = buf[j];
	tmp[v] = '\0';
	return (tmp);
}

//si tmp contient des octes les mets au debut de la ligne
char	*stockpile(char	*ligne, char *tmp)
{
	int	a;

	a = 0;
	if (!tmp)
		return (ligne);
	while (tmp[a] && tmp[a] != '\n')
	{
		ligne[a] = tmp[a];
		a++;
	}
	free (tmp);
	return (ligne);
}

//construit et renvoie la ligne voulu
char	*create_ligne(char *ligne, char *buf)
{
	int	e;
	int	n;
	static	char	*tmp;

	e = 0;
	n = 0;
	tmp = malloc(ft_strlen(buf) * sizeof(char));
	if (!tmp)
		return (NULL);
	ligne = stockpile(ligne, tmp);
	while (ligne[e])
		e++;
	while (buf[n] && buf[n] != '\n')
		ligne[e++] = buf[n++];
	if (buf[n])
		tmp = create_pile(buf, tmp);
	ligne[e] = '\0';
	return (ligne);
}
//fonction principale
char	*get_next_line(int fd)
{
	char	*ligne;
	char	buf[BUFFER_SIZE + 1];
	int	red;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	ligne = malloc(9999999 * sizeof(char) + 1);
	if (!ligne)
		return (NULL);
	while ((red = read(fd, buf, BUFFER_SIZE)))
	{
		buf[red] = '\0';
		if (new_line(buf) == 1)
		{
			ligne = create_ligne(ligne, buf);
			break ;
		}
		else if (new_line(buf) == 0)
			ligne = create_ligne(ligne, buf);
	}
	return (ligne);
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
		printf("%s\n", get_next_line(fd));
		//free(gob);
	}
}
