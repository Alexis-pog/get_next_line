/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:12:41 by acoquele          #+#    #+#             */
/*   Updated: 2021/12/30 12:18:46 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *c)
{
	int		i;

	i = 0;
	if (!c)
		return ((int) NULL);
	while (c[i])
		i++;
	return (i);
}

size_t	ft_strchr(const void *s, int c)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	character;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == character)
			return (str[i]);
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	count;

	if (!s || s == '\0')
		return (NULL);
	count = 0;
	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (ft_strlen((char *)s) - start < len)
		len = ft_strlen((char *)s) - start;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	while (len > 0)
	{
		sub_str[count] = s[start];
		start++;
		count++;
		if (len == 0)
			break ;
		len--;
	}
	sub_str[count] = '\0';
	return (sub_str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*main_str;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1)
		return (ft_strdup(s2));
	main_str = malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!main_str)
		return (NULL);
	while (s1 && s1[i])
	{
		main_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[i2])
		main_str[i++] = s2[i2++];
	main_str[i] = '\0';
	return (main_str);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(char *)s1)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
