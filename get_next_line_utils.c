#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = 0;
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	if (!*s)
		return (NULL);
	while (*s++)
	{
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}

/* Set N bytes of S to C.  */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = c;
	return (s);
}

/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size || ((nmemb * size) > INT_MAX))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', (nmemb * size));
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_free_everything(void *ptr)
{
	free(ptr);
}
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	char	*copied;
// 	int		i;

// 	i = 0;

// 	copied[i] = 0;
// 	return (copied);
// }

// int	ft_read(int fd, char *buf, size_t bytes)
// {

// 	return (0);
// }
