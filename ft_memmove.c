/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:58:23 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 11:58:47 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char	*tmp;
	unsigned char	*src_tmp;

	if (dst == 0 && src == 0)
		return (0);
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
