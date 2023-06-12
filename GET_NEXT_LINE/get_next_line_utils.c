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

#include <stddef.h>

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
