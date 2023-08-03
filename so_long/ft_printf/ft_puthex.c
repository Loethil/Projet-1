/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:01:22 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/29 16:01:26 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_puthex(unsigned int n, int fd, char *base, int *count)
{
	unsigned int	n2;

	n2 = n;
	if (n2 < 16)
		ft_putchar_fd(base[n2], fd, count);
	if (n2 >= 16)
	{
		ft_puthex(n2 / 16, fd, base, count);
		ft_puthex((n2 % 16), fd, base, count);
	}
	return (count);
}
