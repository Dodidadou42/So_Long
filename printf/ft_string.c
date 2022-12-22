/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:13:48 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/17 11:29:32 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, size_t *i)
{
	write(1, &c, 1);
	(*i)++;
}

void	ft_putstr(const char *s, size_t *i)
{
	if (!s)
	{
		ft_putstr("(null)", i);
		return ;
	}
	while (*s)
		ft_putchar(*s++, i);
}
