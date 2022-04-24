/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:52:26 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 11:53:03 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*bb;

	i = 0;
	bb = (unsigned char *) b;
	while (i < len)
		bb[i++] = (unsigned char) c;
	return (b);
}
