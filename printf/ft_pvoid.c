/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pvoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:37:43 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/02 15:37:46 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	*ft_pvoid(unsigned long ptr, int fd, int *count)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd, count);
		return (count);
	}
	ft_putstr_fd("0x", fd, count);
	ft_putadress(ptr, fd, "0123456789abcdef", count);
	return (count);
}
