/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:26:16 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/02 15:26:17 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_hexformat(unsigned int n, int fd, const char c, int *count)
{
	char	*base;

	if (c == 'x')
	{
		base = "0123456789abcdef";
		ft_puthex(n, fd, base, count);
	}
	else if (c == 'X')
	{
		base = "0123456789ABCDEF";
		ft_puthex(n, fd, base, count);
	}
	return (count);
}
