/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:12:23 by acoquele          #+#    #+#             */
/*   Updated: 2021/12/30 12:50:36 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stat
{
	char	buffer[FOPEN_MAX][BUFFER_SIZE];
	size_t	filled[FOPEN_MAX];
}			t_stat;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *c);
size_t	ft_strchr(const void *s, int c);
size_t	ft_find(char *buffer, size_t filled);
void	ft_free(char **ptr);
#endif