/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:53:07 by acoquele          #+#    #+#             */
/*   Updated: 2021/10/24 17:17:40 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *a;
	int buffer;

	buffer = 10;
//	fd = open("README.txt", O_RDONLY);
	//printf("%d",fd);
	a = (char *)malloc(sizeof(char) + 1);
	while(read(fd,a,1) > 0)
	{
//		printf("%s",a);
		//printf("%d",buffer);
		if (ft_memchr(a,'\n',buffer))
			break;
	}
	
	return (a);
}


int main()
{
	char *s;
	int fd;

	fd = open("README.txt", O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
	close(fd);
}

/*
read enable you the possibility to read a file descriptor...
size_t read(int file_descriptor,void *buffer, int nbr_of_byte) 
read :
	send 0 if it reach the end of the fonction;
	send -1 if there is a bug;
i need to find a way to stop the read at the end of the line
the pipe of read is stored in the heap memmory
how to use a struct as a static

*/