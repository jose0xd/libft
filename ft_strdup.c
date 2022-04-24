/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:04:27 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:04:58 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

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
