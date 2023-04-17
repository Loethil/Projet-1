/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:30:22 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/12 14:30:23 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isascii(c) == 1)
	{
		if (ft_isalpha(c) == 1)
		{
			c += 32;
			return (c);
		}
		else if (ft_isalpha(c) == 0)
			return (c);
	}
	return (c);
}
