/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:57:38 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 11:58:04 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*tmp;
	unsigned char	*src_tmp;

	if (dst == 0 && src == 0)
		return (0);
	tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	while (n > 0)
	{
		*tmp++ = *src_tmp++;
		n--;
	}
	return (dst);
}
