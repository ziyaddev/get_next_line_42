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
	static char		*static_buf;
	static char		*str_buf;
	size_t			len;
	char			*newline_found;
	char			*buf;

	(void)static_buf;

	// Don't miss to make some checks on file descriptor like max & min fd ...

	str_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str_buf)
	{
		free(str_buf);
		return (NULL);
	}

	len = 0;
	while (!ft_strchr(static_buf, '\n'))
	{
		/* Set all str_buf bytes to 0 */
		ft_memset(str_buf, '\0', BUFFER_SIZE);

		/* Read BUFFER_SIZE in fd & store it to str_buf */
		read(fd, str_buf, BUFFER_SIZE);

		/* Store address of '\n' char found in str_buf, it will store null ptr if not found */
		newline_found = ft_strchr(str_buf, '\n');

		if (newline_found)
		{
			// strdup || substr || strlcpy ||
			// Calculate lenght until '\n' position & append it to 'len'
			len += (newline_found - str_buf + 1); // +1 for the found character --------------??
			line = ft_calloc((len + 1), sizeof(char)); // +1 for the null terminating char
			if(!line)
			{
				free(line);
				return (NULL);
			}
			// Join everything before '\n'
			ft_strjoin(line, str_buf); // str_buf begining until '\n' included

			// Join everything after '\n'
			static_buf = 0;
		}
		else
		{
			/* Increment line length */
			len += ft_strlen(str_buf); // ----------------------------------------------------??
			buf = malloc(sizeof(char) * ft_strlen(line) + 1);
			if (!buf)
			{
				ft_free_everything(buf);
				return (NULL);
			}
			// > transfert 'line' content to 'buf'
			ft_strjoin(buf, line);
			// > free(line)
			free(line);
			// > malloc 'line' with new length (ft_strlen(buf) + BUFFER_SIZE)
			line = malloc(ft_strlen(buf) + BUFFER_SIZE);
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

	// printf("Get next line function : %s\n", get_next_line(open_testfile_fd));

	free(mem_space);
	free(calloc_mem_space);

	close(open_testfile_fd);
	return (0);
}
