/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:12:41 by acoquele          #+#    #+#             */
/*   Updated: 2021/11/18 16:03:37 by acoquele         ###   ########.fr       */
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
	void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_str;
	char		*src_str;	
	size_t		count;

	if (src == dst)
		return (dst);
	count = -1;
	dst_str = (char *)dst;
	src_str = (char *)src;
	if (src < dst)
	{
		while (len--)
			*(dst_str + len) = *(src_str + len);
		return (dst);
	}
	while (len--)
		*dst_str++ = *src_str++;
	return (dst);
}

}
