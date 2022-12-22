/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:27:17 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/16 17:38:45 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *f, ...);
void	ft_putchar(const char c, size_t *i);
void	ft_putstr(const char *s, size_t *i);
void	ft_putnbr(int nb, size_t *i);
void	ft_putnbr_uns(unsigned int nb, size_t *i);
void	ft_convbase(unsigned long long p, char *base, size_t *i);
int		is_bonus(const char *f, va_list args, size_t *i);

#endif
