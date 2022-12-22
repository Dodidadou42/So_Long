/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:03:39 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/18 18:17:29 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*get_buf(int fd, char *buf)
{
	char	*temp;
	int		n;

	if (!buf)
		buf = ft_calloc(1, 1);
	temp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	n = 1;
	while (n > 0)
	{
		n = read(fd, temp, BUFFER_SIZE);
		if (n == -1)
		{
			free(temp);
			free(buf);
			return (0);
		}
		temp[n] = '\0';
		buf = join_free(buf, temp);
		if (ft_strchr(buf, '\n'))
			n = -1 ;
	}
	free(temp);
	return (buf);
}

char	*ft_get_line(char	*buf)
{
	char	*ret;
	int		i;

	i = 0;
	if (!buf[i])
		return (0);
	while (buf[i] != '\n' && buf[i])
		i++;
	ret = ft_calloc(i + 2, sizeof(char));
	i = -1;
	while (buf[++i] != '\n' && buf[i])
		ret[i] = buf[i];
	if (buf[i] == '\n' && buf[i])
		ret[i] = '\n';
	return (ret);
}

char	*get_next_buf(char	*buf)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free(buf);
		return (0);
	}
	ret = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buf[i])
		ret[j++] = buf[i++];
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (fd < 0)
	{
		if (buf)
		{
			free(buf);
			buf = 0;
		}
		return (0);
	}
	buf = get_buf(fd, buf);
	if (!buf)
	{	
		free(buf);
		return (0);
	}
	ret = ft_get_line(buf);
	buf = get_next_buf(buf);
	return (ret);
}
