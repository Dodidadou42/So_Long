/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:52:19 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/09 13:26:50 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *pt, size_t count)
{
	unsigned int	i;
	char			*pt_bis;

	pt_bis = pt;
	i = 0;
	while (i < count)
	{
		pt_bis[i] = '\0';
		i++;
	}
	return (pt);
}
