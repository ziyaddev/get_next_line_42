// Required functions :
// strjoin	ok
// strchr	ok
// strlen	ok

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*static_buf;
	static char		*str_buf;
	unsigned int	len;
	char			*newline_found;
	char			*buf;

	(void)static_buf;

	str_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str_buf)
	{
		free(str_buf);
		return (NULL);
	}

	len = 0;
	while (!ft_strchr(str_buf, '\n'))
	{
		ft_memset(str_buf, '\0', BUFFER_SIZE);
		read(fd, str_buf, BUFFER_SIZE);
		newline_found = ft_strchr(str_buf, '\n');

		// Increment line length
		len += ft_strlen(str_buf);
		if (newline_found)
		{
			// strdup || substr || strlcpy ||
			// Calculate '\n' position & append it to 'len'
			len += (newline_found - str_buf + 1);
			line = ft_calloc((len + 1), sizeof(char));
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
	unsigned int	mem_space_len;

	my_str = malloc(sizeof(char) * 10);
	if (!my_str)
		return (-1);

	open_testfile_fd = open("./test.txt", O_RDONLY);
	printf("testfile fd open : %d\n", open_testfile_fd);

	// printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	// printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	// printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	printf("\nstr len : %ld\n", ft_strlen("my str len test"));

	printf("\nstr join : %s\n", ft_strjoin("my str len test\\", "|/this is 2nd part"));

	printf("\nstr chr : %s\n", ft_strchr("salam akhi", 'k'));

	mem_space_len = 15;
	mem_space = ft_calloc(mem_space_len, 1);

	for (size_t i = 0; i < mem_space_len; i++)
	{
		printf("memspace %ld : %c\n", i, mem_space[i]);
	}

	printf("\nsizeof : %ld\n", sizeof(char));

	close(open_testfile_fd);
	return (0);
}
