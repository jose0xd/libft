/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:10:02 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:10:44 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	len;
	unsigned int	i;

	start = 0;
	while (is_in_str(s1[start], (char *) set))
		start++;
	len = 0;
	i = 0;
	while (s1[start + i])
	{
		if (!is_in_str(s1[start + i], (char *) set))
			len = i + 1;
		i++;
	}
	return (ft_substr(s1, start, len));
}
