/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoquele <acoquele@student@.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:53:07 by acoquele          #+#    #+#             */
/*   Updated: 2021/10/20 17:24:27 by acoquele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int ft_strlen_modif(char *a)
{
    int i;

    i = 0;
    while(*a++)
        i++;
    printf("%d\n",i);
    return (i);
}

int main(void)
{
    char a[2];
    int fd;
    int buffer;

    buffer = 10;
    fd = open("README.txt", O_RDONLY);
    //printf("%d",fd);
    while(read(fd,a,1) > 0)
        printf("%s",a);
}
/*
read enable you the possibility to read a file descriptor...
size_t read(int file_descriptor,void *buffer, int nbr_of_byte) 
read :
    send 0 if it reach the end of the fonction;
    send -1 if there is a bug;
i need to find a way to stop the read at the end of the line

