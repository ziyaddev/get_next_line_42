// Required functions :
// strjoin	ok
// strchr	ok
// strlen	ok

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str_buf;

	line = malloc(sizeof(char) * 10);
	if(!line)
		return (0);

	str_buf = malloc(sizeof(char) * 5);
	if (!str_buf)
		return (0);

	read(fd, str_buf, 1);
	if (*str_buf)
	{
		while (read(fd, str_buf, BUFFER_SIZE))
		{
			write(1, str_buf, BUFFER_SIZE);
		}

	}
	free(line);
	free(str_buf);
	return (line);
}

int	main(void)
{
	int		open_testfile_fd;
	char	*my_str;

	my_str = malloc(sizeof(char) * 10);
	if (!my_str)
		return (-1);

	open_testfile_fd = open("./test.txt", O_RDONLY);
	printf("testfile fd : %d\n", open_testfile_fd);

	printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	printf("\nresult : %s\n\n", get_next_line(open_testfile_fd));

	printf("\nstr len : %ld\n", ft_strlen("my str len test"));

	printf("\nstr join : %s\n", ft_strjoin("my str len test\\", "|/this is 2nd part"));

	printf("\nstr chr : %s\n", ft_strchr("salam akhi", 'k'));

	close(open_testfile_fd);
	return (0);
}
