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

char	*ft_strjoin(char *ligne, char const *s1, char const *s2)
{
	int		r;
	int		a;

	ligne = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!ligne)
		return (NULL);
	r = -1;
	a = -1;
	while (s1[++r])
		ligne[r] = s1[r];
	while (s2[++a])
		ligne[r++] = s2[a];
	ligne[r] = '\0';
	return (ligne);
}

char	*construct(char	*buf, char *ligne, int buffer)
{
	static	char	*tmp;
	int	r;

	tmp = malloc(buffer * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	r = -1;
	while (++r < buffer)
		tmp[r] = buf[r];
	tmp[r] = '\0';
	r = -1;
	while (tmp[++r] != '\n' && tmp[r])
		ligne[r] = tmp[r];
	ligne[r] = '\0';
	free(tmp);
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
	construct(buf, ligne, BUFFER_SIZE);
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