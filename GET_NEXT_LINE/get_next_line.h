/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:01 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/10 15:27:03 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
void	ft_putstr(char *s)
{
	int	r;

	r = -1;
	while (s[++r])
		ft_putchar(s[r]);
}
int	ft_ligne(char *tab)
{
	int	a;

	a = 0;
	while (tab[a] != '\n' && tab[a])
	{
		a++;
	}
	return (a);
}
#endif
