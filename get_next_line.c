/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakchouc <zakchouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:46:33 by zakchouc          #+#    #+#             */
/*   Updated: 2024/02/19 01:17:15 by zakchouc         ###   ########.fr       */
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

// To-do list :
// - Check max 'nmemb'& 'size' in  (int overflow)

// Required functions :
// strjoin	ok
// strchr	ok
// strlen	ok
// strdup	ok
// substr
// strlcpy

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*static_buf;	// Used to store the remaining chars after '\n'
	char			*str_buf;		// Used to store the read chars from file descriptor
	char			*newline_found;
	char			*buf;
	size_t			len;
	int				i;

	// Don't miss to make some checks on file descriptor like max & min fd ...

	str_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str_buf)
	{
		free(str_buf);
		return (NULL);
	}

	len = 0;
	while (!ft_strchr(str_buf, '\n'))
	{
		/* Set all str_buf bytes to 0 to prevent ...? */
		ft_memset(str_buf, '\0', BUFFER_SIZE);

		/* Read BUFFER_SIZE in fd & store it to str_buf */
		read(fd, str_buf, BUFFER_SIZE);

		/* Store address of '\n' char found in str_buf, it will store null ptr if not found */
		newline_found = ft_strchr(str_buf, '\n');

		if (newline_found)
		{
			// strdup || substr || strlcpy ||
			// Calculate lenght until '\n' position & append it to 'len'
			len += (newline_found - str_buf + 1); // +1 for the found character which is '\n' ----------??
			line = ft_calloc((len + 1), sizeof(char)); // +1 for the null terminating char
			if(!line)
			{
				free(line);
				return (NULL);
			}
			// Join everything before '\n'
			ft_strcpy(line, str_buf); // str_buf begining until '\n' included

			// Join everything after '\n'
			i = 0;
			newline_found++;
			while (newline_found[i])
			{
				static_buf[i] = newline_found[i];
				i++;
			}
		}
		else
		{
			/* Increment line length */
			len += ft_strlen(str_buf); // ----------------------------------------------------??
			buf = malloc(sizeof(char) * ft_strlen(len) + 1);
			if (!buf)
			{
				ft_free_everything(buf);
				return (NULL);
			}
			// > transfert 'static_buf' content to 'buf'
			ft_strcpy(buf, str_buf);
			// > free(static_buf)
			free(static_buf);
			// > malloc 'static_buf' with new length (ft_strlen(buf) + BUFFER_SIZE)
			static_buf = malloc(ft_strlen(buf) + BUFFER_SIZE);
			// > copy 'buf' + 'str_buf' into 'line'
			ft_strjoin(line, str_buf); // str_buf begining until '\n' included

		}

		len += BUFFER_SIZE;
	}

	// free(str_buf);
	return (line);
}

int	main(void)
{
	int				open_testfile_fd;
	char			*my_str;
	char			*mem_space;
	char			*calloc_mem_space;
	unsigned int	mem_space_len;
	int				calloc_size;
	char			*str_test =  "This is a string test !";

	my_str = malloc(sizeof(char) * 10);
	if (!my_str)
		return (-1);

	open_testfile_fd = open("./test.txt", O_RDONLY);
	if (open_testfile_fd < 0)
		return (-1);

	printf("Opened file descriptor : %d\n", open_testfile_fd);

	// printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	// printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	// printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	printf("\nstr len : %ld\n", ft_strlen("my str len test"));

	printf("\nstr join : %s\n", ft_strjoin("my str len test\\", "|/this is 2nd part"));

	printf("\nstr chr : %s\n", ft_strchr("salam akhi", 'k'));

	mem_space_len = 6;
	calloc_size = 6500;

	mem_space = ft_calloc(mem_space_len, calloc_size);
	calloc_mem_space = calloc(mem_space_len, calloc_size);

	for (size_t i = 0; i < mem_space_len; i++)
	{
		printf("ft_calloc memspace %ld : %c\t", i, mem_space[i]);
		printf("calloc memspace %ld : %c\n", i, calloc_mem_space[i]);
	}

	printf("\nmemspace : %s\n", mem_space);

	printf("ptr 'T' : %p\n", ft_strchr(str_test, 'T'));
	printf("ptr 'e' : %p\n", ft_strchr(str_test, 'e'));

	printf("len diff : %ld\n", ft_strchr(str_test, 'e') - ft_strchr(str_test, 'T'));

	printf("Get next line function : %s\n", get_next_line(open_testfile_fd));
	printf("Get next line function : %s\n", get_next_line(open_testfile_fd));
	printf("Get next line function : %s\n", get_next_line(open_testfile_fd));
	printf("Get next line function : %s\n", get_next_line(open_testfile_fd));

	free(mem_space);
	free(calloc_mem_space);

	close(open_testfile_fd);
	return (0);
}
