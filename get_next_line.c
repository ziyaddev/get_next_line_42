#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char *) * 10);
	if(!line)
		return (0);
	
	while (i < 10)
	{
		line[i] = fd + i;
		i++;
	}

	return (line);
}

int	main(void)
{
	int my_int;

	my_int = 60;
	printf("\nresult : %s\n\n", get_next_line(my_int));
	return (0);
}
