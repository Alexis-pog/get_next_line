/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:12:41 by acoquele          #+#    #+#             */
/*   Updated: 2021/10/24 17:16:33 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	character;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char) c;
	while (i < n)
	{
		if (*str == character)
			return (i);
		i++;
		str++;
	}
	return (-1);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_str;
	char		*src_str;	

	if (src == dst)
		return (dst);

	dst_str = (char *)dst;
	src_str = (char *)src;

	while (len--)
		*dst_str++ = *src_str++;

	return (dst);
}
