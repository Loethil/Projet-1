/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:41:06 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/20 17:41:07 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_putnbr_fd(int n, int fd, int *count)
{
	long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		n2 *= -1;
		ft_putchar_fd('-', fd, count);
	}
	if (n2 > 9)
	{
		ft_putnbr_fd(n2 / 10, fd, count);
		ft_putchar_fd((n2 % 10) + '0', fd, count);
	}
	else
		ft_putchar_fd(n2 + '0', fd, count);
	return (count);
}
