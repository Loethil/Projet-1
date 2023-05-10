/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:01:32 by mbatteux          #+#    #+#             */
/*   Updated: 2023/05/02 17:01:33 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

void		ft_putchar_fd(char c, int fd, int *count);
size_t		ft_strlen(const char *str);
int			*ft_putstr_fd(char *s, int fd, int *count);
int			*ft_putnbr_fd(int n, int fd, int *count);
int			*ft_putnbrpos_fd(unsigned int n, int fd, int *count);
int			*ft_puthex(unsigned int n, int fd, char *base, int *count);
int			*ft_putadress(unsigned long ptr, int fd, char *base, int *count);
int			*ft_hexformat(unsigned int n, int fd, const char c, int *count);
int			*ft_pvoid(unsigned long ptr, int fd, int *count);
int			ft_printf(const char *s, ...);

#endif
