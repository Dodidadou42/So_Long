/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:03:38 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/15 15:14:26 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ret;

	if (elementSize == SIZE_MAX && elementCount == SIZE_MAX)
		return (0);
	if (elementSize == 0 || elementCount == 0)
	{
		elementSize = 0;
		elementCount = 0;
	}
	ret = malloc(elementSize * elementCount);
	if (!ret)
		return (0);
	ft_bzero(ret, elementCount * elementSize);
	return (ret);
}
