#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, unsigned int n);

char	*ft_strnstr(const char *haystack, const char *needle,
					unsigned int len);

char	*ft_strdup(const char *s1);
