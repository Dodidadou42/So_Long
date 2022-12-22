/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:45:58 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/17 11:19:31 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check(const char *f, va_list args, size_t *i)
{
	if (*f == 'c')
		ft_putchar((char)va_arg(args, int), i);
	if (*f == 's')
		ft_putstr((char *)va_arg(args, char *), i);
	if (*f == 'd' || *f == 'i')
		ft_putnbr(va_arg(args, int), i);
	if (*f == 'p')
	{
		ft_putstr("0x", i);
		ft_convbase(va_arg(args, unsigned long long),
			"0123456789abcdef", i);
	}
	if (*f == 'u')
		ft_putnbr_uns(va_arg(args, unsigned int), i);
	if (*f == 'x')
		ft_convbase(va_arg(args, unsigned int), "0123456789abcdef", i);
	if (*f == 'X')
		ft_convbase(va_arg(args, unsigned int), "0123456789ABCDEF", i);
	if (*f == '%' || !(*f))
		ft_putchar('%', i);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, f);
	while (*f)
	{
		while (*f != '%' && *f)
			ft_putchar(*(f++), &i);
		if (!*f)
			return (i);
		if (*f == '%' && *(f + 1))
			check(++f, args, &i);
		f++;
	}
	return (i);
}
