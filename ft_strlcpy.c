/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:59:24 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 11:59:31 by jarredon         ###   ########.fr       */
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
