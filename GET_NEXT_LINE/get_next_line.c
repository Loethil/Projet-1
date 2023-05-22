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
	int	a;

	r = 0;
	a = 0;
	while (buf[r])
	{	
		if (buf[r] == '\n')
			a++;
		r++;
	}
	return (a);
}

//cree le tableau de chaine de caractere temporaire
char	*create_pile(char *buf, char **tmp)
{
	int	v;
	int	e;

	v = 0;
	e = 0;

}

//rajoute ce qui est stocke dans tmp au debut de line
char	*stockpile(char *line, char **tmp)
{
	
}

//construit et renvoie la ligne voulu
char	*create_line(char *line, char *buf)
{
	static char **tmp;
	static	int	i = 0;

	tmp = malloc((new_line(buf) + 1) * sizeof(**char) + 1)
	if (!tmp)
		return (NULL);

	i++;
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
	line = malloc(9999999 * sizeof(char) + 1);
	if (!line)
		return (NULL);
	while ((red = read(fd, buf, BUFFER_SIZE)))
	{
		buf[red] = '\0';
		if (new_line(buf) > 0)
		{
			line = create_line(line, buf);
			break ;
		}
		else if (new_line(buf) == 0)
			line = create_line(line, buf);
	}
	return (line);
}