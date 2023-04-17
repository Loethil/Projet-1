/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:50:48 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/15 22:50:49 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	r;
	size_t	a;
	char	*tab;

	r = start;
	a = 0;
	tab = (char *) malloc(len + 1 * sizeof(char));
	while (r < start + len)
	{
		tab[a] = s[r];
		a++;
		r++;
	}
	tab[a] = '\0';
	return (tab);
}
