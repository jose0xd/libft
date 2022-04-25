/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:02:59 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/25 19:52:57 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	len_ndl;
	unsigned int	i;

	len_ndl = ft_strlen(needle);
	if (len_ndl == 0)
		return ((char *) haystack);
	if (len == 0)
		return (0);
	i = 0;
	while (haystack[i] && i <= (len - len_ndl))
	{
		if (!ft_strncmp(&haystack[i], needle, len_ndl))
			return ((char *) &haystack[i]);
		i++;
	}
	return (0);
}
