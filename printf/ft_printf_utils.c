/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:36:54 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:40:46 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_len_num(long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char	ft_printf_getsign(t_print *tab, long n)
{
	if ((tab->sign || tab->sp) && n >= 0)
	{
		if (tab->sign)
			return ('+');
		else
			return (' ');
	}
	if (n < 0)
	{
		return ('-');
	}
	return (0);
}

int	ft_printf_fill(char c, int len)
{
	int	ret;

	ret = 0;
	while (len-- > 0)
		ret += ft_printf_putchar(c);
	return (ret);
}
