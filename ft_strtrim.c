/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:05:46 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/17 11:05:47 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	howmanystart(char const *s1, char const *set)
{
	int	v;
	int	e;

	v = 0;
	e = 0;
	while (set[e])
	{
		if (s1[v] != set[e])
			e++;
		else if (s1[v++] == set[e])
			e = 0;
	}
	return (v);
}

int	howmanyend(char const *s1, char const *set)
{
	int	v;
	int	e;

	v = ft_strlen(s1) - 1;
	e = 0;
	while (set[e])
	{
		if (s1[v] != set[e])
			e++;
		else if (s1[v--] == set[e])
			e = 0;
	}
	return (v + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	r;
	size_t	a;
	size_t	n;
	char	*tab;

	r = howmanystart(s1, set);
	a = 0;
	n = howmanyend(s1, set);
	tab = (char *) malloc(ft_strlen(s1) * sizeof(char));
	while (r < n)
	{
		tab[a++] = s1[r++];
	}
	return (tab);
}

/*int	main(void)
{
	printf("%s\n", ft_strtrim("./;bonjour;/.", "./e;"));
	printf("%d\n", howmanyE("./;bonjour;/.", "./e;"));
	printf("%d\n", howmanyS("./;bonjour;/.", "./e;"));
	printf("%ld\n", ft_strlen("./;bonjour;/."));
}*/
