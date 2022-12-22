/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:03:39 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/18 15:35:33 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	free(s1);
	return (ret);
}
