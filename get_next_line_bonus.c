/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:44:56 by acoquele          #+#    #+#             */
/*   Updated: 2021/12/30 10:44:56 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*c;
	char		*dest_str;

	if (dest == src)
		return (NULL);
	c = (char *) src;
	dest_str = (char *) dest;
	while (n-- > 0)
		*(dest_str++) = *c++;
	return (dest);
}

size_t	ft_find(char *buffer, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled)
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

int	change_r(char *buffer, char **r, size_t *filled)
{
	const size_t	nl = ft_find(buffer, *filled);
	char *const		sub = ft_substr(buffer, 0, nl + (nl != *filled));
	char			*r_tmp;

	if (!sub)
		return (0);
	r_tmp = ft_strjoin(*r, sub);
	free(sub);
	if (!r_tmp)
		return (0);
	free (*r);
	*r = r_tmp;
	if (nl == *filled)
		*filled = 0;
	else
	{
		ft_memcpy(buffer, buffer + nl + 1, *filled - nl - 1);
		*filled -= nl + 1;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_stat	stat;
	ssize_t			n;
	char			*r;

	if (fd < 0 || fd > FOPEN_MAX)
		return (0);
	r = 0;
	while (1)
	{
		n = read(fd, stat.buffer[fd] + stat.filled[fd],
				BUFFER_SIZE - stat.filled[fd]);
		stat.filled[fd] += n;
		if (n == 0 && stat.filled[fd] == 0)
			return (r);
		if (n == -1 || !change_r(stat.buffer[fd], &r, &stat.filled[fd]))
		{
			stat.filled[fd] = 0;
			free(r);
			return (0);
		}
		if (r[ft_strlen(r) - 1] == '\n')
			return (r);
	}
}
