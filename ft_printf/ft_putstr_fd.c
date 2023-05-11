/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:32:17 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/20 17:32:19 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_putstr_fd(char *s, int fd, int *count)
{
	int	r;

	r = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", fd, count);
		return (count);
	}
	while (s[r])
		ft_putchar_fd(s[r++], fd, count);
	return (count);
}
