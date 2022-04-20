/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:41:20 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/20 13:13:05 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *) &s[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	len_hay;
	unsigned int	len_ndl;
	unsigned int	i;

	len_hay = ft_strlen(haystack);
	len_ndl = ft_strlen(needle);
	if (len_ndl == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i < (len - len_ndl))
	{
		if (!ft_strncmp(&haystack[i], needle, len_ndl))
			return ((char *) &haystack[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	char			*copy;
	char			*tmp;

	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == 0)
	{
		errno = ENOMEM;
		return (0);
	}
	tmp = copy;
	while (*s1)
	{
		*tmp++ = *s1++;
	}
	*tmp = '\0';
	return (copy);
}
