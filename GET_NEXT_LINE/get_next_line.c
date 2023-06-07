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

int	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i])
		i++;
	return (i);
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

char	*ft_strjoin(char const *temp, char const *buf)
{
	char	*tab;
	int		r;
	int		a;

	tab = (char *)malloc ((ft_strlen(temp) + ft_strlen(buf) + 1) * sizeof (char));
	if (!tab)
		return (NULL);
	r = -1;
	a = -1;
	while (temp[++r])
		tab[r] = temp[r];
	while (buf[++a])
		tab[r++] = buf[a];
	tab[r] = '\0';
	return (tab);
}

char	*choose (char	*line, int d)
{
	int	r = 0;
	int	a = 0;
	char	*tmp;

	if (d == 1)
	{
		while (*line && line[r] && line[r] != '\n')
			r++;
		line[++r] = '\0';
		return (line);
	}
	else if (d == 2)
	{
		tmp = malloc(sizeof(char) * 10000000);
		if (!tmp)
			return (NULL);
		while (*line && line[r] && line[r] != '\n')
			r++;
		while (*line && line[++r] != '\0')
			tmp[a++] = line[r];
		tmp[a] = '\0';
		line = tmp;
		free (tmp);
		return (line);
	}
	return (line);
}
char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		red;
	char		*line;
	static char	*stk;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	stk = malloc(10000000 * sizeof(char));
	while (red > 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		buf[red] = '\0';
		temp = stk;
		stk = ft_strjoin(temp, buf);
		free (temp);
		if (new_line(stk) == 1)
			break;
	}
	line = choose(stk, 1);
	temp = stk;
	stk = choose(temp, 2);
	free (temp);
	if (red == 0)
	{
		free (line);
		line = NULL;
		return (NULL);
		
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*gob;

	//gob = malloc(10000000 * sizeof(char));
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		gob = get_next_line(fd);
		while (gob != NULL)
		{
			printf ("%s", gob);
			free (gob);
			gob = get_next_line(fd);
		}
	}
	return (0);
}
