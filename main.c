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
	char *buffer_read;
  char *buffer_line;
  char *start_line;
  static char *tmp_line;
  static int tmp_size;
	int buffer_size;
  int search_index;
  int read_count;

	buffer_size = 10;
	buffer_read = (char *)malloc(sizeof(char) * buffer_size);
	buffer_line = (char *)malloc(sizeof(char) * 1000);
  start_line = buffer_line;
  
  if (tmp_size > 0)
  {
    ft_memmove(buffer_line, tmp_line, tmp_size);
    buffer_line = buffer_line + tmp_size;
    free(tmp_line);
    tmp_line = NULL;
    tmp_size = 0;
  }

	tmp_line = (char *)malloc(sizeof(char) * buffer_size);

	while((read_count = read(fd, buffer_read, buffer_size)) > 0)
	{
		if ((search_index = ft_memchr(buffer_read,'\n',buffer_size)) >= 0)
    {
      // Copy up to \n into buffer_lean
      ft_memmove(buffer_line, buffer_read, 1 + search_index);
      buffer_line = buffer_line + (1 + search_index);
      // Save the rest of it into static variable
      ft_memmove(tmp_line, buffer_read, buffer_size - search_index - 1);
      tmp_size = buffer_size - search_index - 1;
      break;
    }
    else
    {
      // Copy content of buffer_read to buffer_line
      ft_memmove(buffer_line, buffer_read, buffer_size);
      buffer_line = buffer_line + buffer_size;
    }
	}

  if (read_count == 0)
    return 0;
	
  free(buffer_read);
  buffer_read = NULL;
	return (start_line);
}


int main()
{
	char *s;
	int fd;

	fd = open("README.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
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
