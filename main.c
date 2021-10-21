/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:53:07 by acoquele          #+#    #+#             */
/*   Updated: 2021/10/21 11:49:47 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

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

void	*ft_memchr(const void *s, int c, size_t n)
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
			return (str);
		i++;
		str++;
	}
	return (NULL);
}

int ft_strlen_modif(char *a)
{
    int i;

    i = 0;
    while(*a++)
        i++;
    printf("%d\n",i);
    return (i);
}

char *get_next_line(void)
{
    char a[2];
    int fd;
    int buffer;

    buffer = 10;
    fd = open("README.txt", O_RDONLY);
    //printf("%d",fd);
    while((buffer = read(fd,a,1)) > 0)
    {
        printf("%s",a);
        //printf("%d\n",buffer);
        if (ft_memchr(a,'\n',buffer))
            break;
    }
    return (a);
}
int main()
{
    int index = 10;
    while (index-- > 0)
        get_next_line();        
}

/*
read enable you the possibility to read a file descriptor...
size_t read(int file_descriptor,void *buffer, int nbr_of_byte) 
read :
    send 0 if it reach the end of the fonction;
    send -1 if there is a bug;
i need to find a way to stop the read at the end of the line
the pipe of read is stored in the heap memmory


*/