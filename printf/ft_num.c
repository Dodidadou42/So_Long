/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:44:30 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/17 11:29:29 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, size_t *i)
{	
	if (nb < -2147483647)
	{
		write(1, "-2147483648", 11);
		*i += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', i);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putchar(nb % 10 + '0', i);
	}
	else
		ft_putchar(nb + '0', i);
}

void	ft_putnbr_uns(unsigned int nb, size_t *i)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putchar(nb % 10 + '0', i);
	}
	else
		ft_putchar(nb + '0', i);
}

void	ft_convbase(unsigned long long p, char *base, size_t *i)
{
	if (p > 15)
	{
		ft_convbase(p / 16, base, i);
		ft_putchar(base[p % 16], i);
	}
	else
		ft_putchar(base[p], i);
}
