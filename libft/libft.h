/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddychus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:48:27 by ddychus           #+#    #+#             */
/*   Updated: 2022/11/15 16:34:27 by ddychus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

size_t			ft_strlen(const char *str);
void			*ft_bzero(void *pt, size_t count);
char			*ft_strchr(const char *str, int searchedChar);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *source);
void			*ft_calloc(size_t elementCount, size_t elementSize);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
#endif
