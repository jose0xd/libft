/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:05:57 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/25 18:16:02 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned long count, unsigned long size)
{
	char			*ptr;
	unsigned int	i;

	if (count + size < count || count + size < size)
		return (0);
	ptr = (char *) malloc(count * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < (count * size))
		ptr[i++] = 0;
	return ((void *) ptr);
}
