/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string-2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:31 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/20 18:35:43 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (*src && size-- > 1)
	{
		*dst++ = *src++;
		len++;
	}
	*dst = '\0';
	while (*src++)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*dst && size)
	{
		len++;
		dst++;
		size--;
	}
	while (*src && size > 1)
	{
		*dst++ = *src++;
		len++;
		size--;
	}
	if (size)
		*dst = '\0';
	while (*src++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
		return (ptr);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (*s == c)
		ptr = (char *)s;
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i >= n)
		return (0);
	else
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
