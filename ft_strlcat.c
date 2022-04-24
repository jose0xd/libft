/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:59:44 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:00:03 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
