/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:46:33 by zakchouc          #+#    #+#             */
/*   Updated: 2023/12/05 20:46:36 by zakchouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @author Ziyad A. Dev (zakchouc@student.42.fr)
 * @brief		Write a function that returns a line read from a file descriptor
 * 				Allowed functions(s) : read, malloc, free
 * @param fd	The file descriptor to read from
 * @return		Read line : correct behavior 
 * 				NULL : there is nothing else to read, or an error occurred
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// ssize_t read(int fd, void *buf, size_t count);

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		i;
	int		j;
	char	*buf;
	
	i = 10;
	j = 0;

	buf = malloc(sizeof(char) *10);
	if (!buf)
		return ((void *)0);
	while (read(fd, buf, i) != -1)
	{
		j++;
	}

	return (buf);
}

int	main(void)
{
	char *buf;

	buf = malloc(sizeof(char) * 10);
	if (!buf)
		return (0);
	
	open("/home/zakchouc/projects/get_next_line/text.txt", )
	write(5, "salut\n", 6);
	read(5, buf, 10);
	printf("my buf : %s\n", buf);
	// get_next_line(5);
	return (0);
}