/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:12:11 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:12:54 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#define SIZE 20

char	*ft_itoa(int n)
{
	char	cache[SIZE];
	int		i;
	long	num;
	int		sign;

	i = SIZE - 1;
	num = (long) n;
	sign = 0;
	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	cache[i--] = '\0';
	while (num > 0)
	{
		cache[i--] = (char)(num % 10 + '0');
		num /= 10;
	}
	if (sign)
		cache[i--] = '-';
	if (n == 0)
		cache[i--] = '0';
	return (ft_strdup(&cache[i + 1]));
}
