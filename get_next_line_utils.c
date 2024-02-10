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
