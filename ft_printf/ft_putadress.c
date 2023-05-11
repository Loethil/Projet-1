/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:38:37 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/03 15:38:39 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_putadress(unsigned long ptr, int fd, char *base, int *count)
{
	unsigned long	n2;

	n2 = ptr;
	if (n2 < 16)
		ft_putchar_fd(base[n2], fd, count);
	if (n2 >= 16)
	{
		ft_putadress(n2 / 16, fd, base, count);
		ft_putadress(n2 % 16, fd, base, count);
	}
	return (count);
}
