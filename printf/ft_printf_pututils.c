/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:16:57 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:41:37 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static const char	g_hex[16] = "0123456789abcdef";

static const char	g_hex_upper[16] = "0123456789ABCDEF";

int	ft_printf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

long	ft_printf_putsign(t_print *tab, long n)
{
	if (n < 0)
	{
		if (tab->dash)
			tab->tl += ft_printf_putchar('-');
		n = -n;
	}
	return (n);
}

int	ft_printf_putuns(unsigned int num)
{
	int	len;

	len = 0;
	if (num < 10)
		len += ft_printf_putchar((char)(num + '0'));
	else
	{
		len += ft_printf_putuns((num / 10));
		len += ft_printf_putchar((char)(num % 10 + '0'));
	}
	return (len);
}

int	ft_printf_puthex(unsigned long n, char upper)
{
	int	len;

	len = 0;
	if (n < 16)
	{
		if (upper)
			ft_printf_putchar(g_hex_upper[n]);
		else
			ft_printf_putchar(g_hex[n]);
		len++;
	}
	else
	{
		len += ft_printf_puthex(n / 16, upper);
		if (upper)
			ft_printf_putchar(g_hex_upper[n % 16]);
		else
			ft_printf_putchar(g_hex[n % 16]);
		len++;
	}
	return (len);
}
