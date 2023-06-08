/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:33 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/10 15:27:34 by mbatteux         ###   ########.fr       */
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

char	*superstock(char *stk)
{
	int	v;
	int	e;
	int	n;
	char	*tab;

	v = 0;
	e = 0;
	tab = malloc (ft_strlen(stk) * sizeof(char));
	while (*stk && stk[e])
	{
		tab[e] = stk[e];
		e++;
	}
	stk = NULL;
	while (*tab && tab[v] != '\n')
		v++;
	n = v;
	e = 0;
	while (*tab && tab[++n])
		stk[e++] = tab[n];
	stk[e] = 0;
	tab[++v] = 0;
	return (tab);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		red;
	char		*line;
	static char	*stk;
	char		*temp;

	red = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	stk = malloc(10000000 * sizeof(char));
	if (!stk)
		return (NULL);
	if (*stk && new_line(stk) == 1)
	{
		temp = superstock(stk);
		line = temp;
		temp = NULL;
		free (temp);
		return (line);
	}
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


}
