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

void	ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[k])
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = 0;
}

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
		tmp = malloc(sizeof(char) * 2147478364);
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

char	*get_next_line(int fd)
{
	static char		*stk;
	char			*buf;
	char			*line;
	char			*temp;
	int		red;

	red = 1;
	buf = malloc (2147478364 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
	{
		free (buf);
		return (NULL);
	}
	if (stk == NULL)
	{
		stk = malloc(2147478364 * sizeof(char));
		stk[0] = 0;
	}
	if (!stk)
		return (NULL);
	while (red > 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		buf[red] = '\0';
		ft_strcat(stk, buf);
		if (new_line(stk) == 1)
			break;
	}
	free (buf);
	if (red == 0 && !(*stk))
	{
		free (stk);
		stk = NULL;
		return (NULL);
	}
	temp = choose(stk, 2, 0, 0);
	line = choose(stk, 1, 0, 0);
	stk = temp;
	// printf("steak = %s\n", stk);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int	fd;
// 	char	*gob;

// 	//gob = malloc(10000000 * sizeof(char));
// 	if (argc > 1)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		gob = get_next_line(fd);
// 		while (gob != NULL)
// 		{
// 			printf ("%s", gob);
// 			free (gob);
// 			gob = get_next_line(fd);
// 		}
// 		gob = get_next_line(fd);
// 	}
// 	return (0);
// }
