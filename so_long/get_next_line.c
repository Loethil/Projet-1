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

char	*choose(char *line, int d, int r, int a)
{
	char	*tmp;

	if (line == NULL)
		return (line);
	if (d == 1)
	{
		while (*line && line[r] != '\n' && line[r])
			r++;
		line[++r] = '\0';
		return (line);
	}
	else if (d == 2)
	{
		tmp = malloc(sizeof(char) * 10000);
		if (!tmp)
			return (NULL);
		while (*line && line[r] != '\n' && line[r] != '\0')
			r++;
		while (line[r] && line[++r] != '\0')
			tmp[a++] = line[r];
		tmp[a] = '\0';
		return (tmp);
	}
	return (line);
}

char	*readplswait(char *buf, int fd, char *stk, int red)
{
	while (red > 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		buf[red] = '\0';
		ft_strcat(stk, buf);
		if (new_line(stk) == 1)
			break ;
	}
	free (buf);
	if (red == 0 && !(*stk))
	{
		free (stk);
		stk = NULL;
		return (NULL);
	}
	return (stk);
}

char	*get_next_line(int fd)
{
	static char		*stk;
	char			*buf;
	char			*line;
	char			*temp;
	int				red;

	red = 1;
	buf = malloc (10000 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
	{
		free (buf);
		return (NULL);
	}
	if (stk == NULL)
	{
		stk = malloc(10000 * sizeof(char));
		stk[0] = 0;
	}
	if (!stk)
		return (NULL);
	stk = readplswait(buf, fd, stk, red);
	temp = choose(stk, 2, 0, 0);
	line = choose(stk, 1, 0, 0);
	stk = temp;
	return (line);
}
