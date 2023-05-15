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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		r;
	int		a;
	char	*ligne;

	ligne = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!ligne)
		return (NULL);
	r = -1;
	a = -1;
	while (s1[++r])
		ligne[r] = s1[r];
	while (s2[++a] != '\n' || s2[a])
		ligne[r++] = s2[a];
	ligne[r] = '\0';
	return (ligne);
}

char	*construct(int	fd, char *buf, char *ligne, int buffer)
{
	int	a;
	char	*s2;

	s2 = malloc(buffer * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	a = read(fd, s2, buffer);
	s2[a] = '\0';
	ligne = ft_strjoin(buf, s2);
	return (ligne);
}

char	*get_next_line(int fd)
{
	int	ret;
	char	buf[BUFFER_SIZE + 1];
	char	*ligne;

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	ligne = malloc(BUFFER_SIZE * sizeof(char) + 1);
	construct(fd, buf, ligne, BUFFER_SIZE);
	return (ligne);
}

int	main(int argc, char **argv)
{
	int	fd;

	if(argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%s", get_next_line(fd));
	}
}