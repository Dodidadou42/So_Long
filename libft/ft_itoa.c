/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:22:47 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/15 15:22:50 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:09 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/15 15:22:08 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*intmin(char *ret)
{
	ret[0] = '-';
	ret[1] = '2';
	ret[2] = '1';
	ret[3] = '4';
	ret[4] = '7';
	ret[5] = '4';
	ret[6] = '8';
	ret[7] = '3';
	ret[8] = '6';
	ret[9] = '4';
	ret[10] = '8';
	ret[11] = '\0';
	return (ret);
}

char	*ft_itoa2(long nb, char *ret, int sign, int len)
{
	if (nb < 0)
	{
		sign = 0;
		ret[sign] = '-';
		nb = -nb;
	}
	ret[len--] = '\0';
	if (nb == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	while (len > sign)
	{
		ret[len] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	long	nb;
	int		sign;

	sign = -1;
	nb = (long)n;
	len = get_len(n);
	if (nb == -2147483648)
	{
		ret = malloc(sizeof(char) * 12);
		if (!ret)
			return (0);
		return (intmin(ret));
	}
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret = ft_itoa2(nb, ret, sign, len);
	return (ret);
}
