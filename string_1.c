/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:04 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/19 13:21:13 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h> // borrar

unsigned int	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char *) b;
	while (i < len)
		bb[i++] = (unsigned char) c;
	return (b);
}

void	ft_bzero(void *s, unsigned int n)
{
	char	*ss;

	ss = (char *) s;
	while (n > 0)
	{
		*ss++ = 0;
		n--;
	}
}

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*tmp;
	unsigned char	*src_tmp;

	tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	while (n > 0)
	{
		*tmp++ = *src_tmp++;
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char	*tmp;
	unsigned char	*src_tmp;

	tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	if (src_tmp > tmp)
	{
		while (tmp < ((unsigned char *) dst + len))
			*tmp++ = *src_tmp++;
	}
	else
	{
		tmp = tmp + len - 1;
		src_tmp = src_tmp + len - 1;
		while (tmp >= (unsigned char *) dst)
			*tmp-- = *src_tmp--;
	}
	return (dst);
}
