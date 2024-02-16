#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

void	*ft_memset(void *s, int c, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(const char *s);

void	ft_free_everything(void *ptr);

#endif
