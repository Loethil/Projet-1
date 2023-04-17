/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:02:25 by mbatteux          #+#    #+#             */
/*   Updated: 2023/04/12 14:02:28 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isascii(c) == 1)
	{
		if (ft_isalpha(c) == 1)
		{
			c -= 32;
			return (c);
		}
		else if (ft_isalpha(c) == 0)
			return (c);
	}
	return (c);
}
