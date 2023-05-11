/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:16:30 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/28 13:16:32 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_format(const char *s, va_list args, int *count, int r)
{
	if (s[r] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	else if (s[r] == '\n')
		ft_putchar_fd('\n', 1, count);
	else if (s[r] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (s[r] == 'i' || s[r] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (s[r] == 'u')
		ft_putnbrpos_fd(va_arg(args, unsigned int), 1, count);
	else if (s[r] == 'x' || s[r] == 'X')
		ft_hexformat(va_arg(args, int), 1, s[r], count);
	else if (s[r] == 'p')
		ft_pvoid((unsigned long)va_arg(args, void *), 1, count);
	else if (s[r++] == '%')
		ft_putchar_fd('%', 1, count);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;
	int			r;

	count = 0;
	r = 0;
	va_start(args, *s);
	while (s[r])
	{
		if (s[r] == '%')
			ft_format(s, args, &count, ++r);
		else
			ft_putchar_fd(s[r], 1, &count);
		r++;
	}	
	va_end(args);
	return (count);
}
