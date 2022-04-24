/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:05:57 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:06:39 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	char			*ptr;
	unsigned int	i;

	ptr = (char *) malloc(count * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < (count * size))
		ptr[i++] = 0;
	return ((void *) ptr);
}
