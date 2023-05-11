/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpos_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:14:19 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/28 16:14:20 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_putnbrpos_fd(unsigned int n, int fd, int *count)
{
	unsigned long int	n2;

	n2 = n;
	if (n2 > 9)
	{
		ft_putnbrpos_fd(n2 / 10, fd, count);
		ft_putchar_fd((n2 % 10) + '0', fd, count);
	}
	else
		ft_putchar_fd(n2 + '0', fd, count);
	return (count);
}
