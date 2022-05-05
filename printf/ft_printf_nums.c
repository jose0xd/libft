/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:19:26 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:54:44 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void	ft_padding(t_print *tab, int len, char sign)
{
	char	pad;

	pad = ' ';
	if (tab->zero)
		pad = '0';
	if (tab->prc >= len)
	{
		len = tab->prc;
		if (sign)
			len++;
	}
	if (!tab->dash && sign && pad == '0' && !tab->prc)
		tab->tl += ft_printf_putchar(sign);
	if (tab->prc > 0)
		while (len++ < tab->wdt)
			tab->tl += ft_printf_putchar(' ');
	else
		while (len++ < tab->wdt)
			tab->tl += ft_printf_putchar(pad);
	if (!tab->dash && sign && (pad == ' ' || tab->prc))
		tab->tl += ft_printf_putchar(sign);
}

void	ft_printf_pointer(t_print *tab)
{
	void			*ptr;
	int				len;
	unsigned long	n;

	ptr = va_arg(tab->args, void *);
	len = 2;
	n = (unsigned long) ptr;
	if (n == 0 && !tab->pnt)
		len++;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	if (!tab->dash)
		ft_padding(tab, len, 0);
	tab->tl += ft_printf_putstr("0x");
	if (!(tab->pnt && ptr == 0))
		tab->tl += ft_printf_puthex((unsigned long) ptr, 0);
	if (tab->dash)
		ft_padding(tab, len, 0);
}

void	ft_printf_int(t_print *tab)
{
	long	n;
	int		len;
	char	sign;
	int		extra;

	n = va_arg(tab->args, int);
	len = ft_printf_len_num(n, 10);
	extra = 0;
	sign = ft_printf_getsign(tab, n);
	if (sign)
		extra = 1;
	if (!tab->dash)
		ft_padding(tab, len + extra, sign);
	n = ft_printf_putsign(tab, n);
	tab->tl += ft_printf_fill('0', tab->prc - len);
	if (n == 0 && tab->pnt && tab->prc == 0)
	{
		if (tab->wdt)
			tab->tl += ft_printf_putchar(' ');
	}
	else
		tab->tl += ft_printf_putuns((unsigned int) n);
	if (tab->dash)
		ft_padding(tab, len + extra, sign);
}

void	ft_printf_unsigned(t_print *tab)
{
	unsigned int	n;
	int				len;

	n = va_arg(tab->args, unsigned int);
	len = ft_printf_len_num((long) n, 10);
	if (!tab->dash)
		ft_padding(tab, len, 0);
	tab->tl += ft_printf_fill('0', tab->prc - len);
	if (n == 0 && tab->pnt && tab->prc == 0 && tab->wdt)
		tab->tl += ft_printf_putchar(' ');
	else if (!(n == 0 && tab->pnt && tab->prc == 0))
		tab->tl += ft_printf_putuns(n);
	if (tab->dash)
		ft_padding(tab, len, 0);
}

void	ft_printf_hex(t_print *tab, char upper)
{
	unsigned int	n;
	int				len;

	n = va_arg(tab->args, unsigned int);
	len = ft_printf_len_num((long) n, 16);
	if (!tab->dash)
		ft_padding(tab, len, 0);
	if (tab->sharp && n != 0)
	{
		if (upper)
			tab->tl += ft_printf_putstr("0X");
		else
			tab->tl += ft_printf_putstr("0x");
	}
	tab->tl += ft_printf_fill('0', tab->prc - len);
	if (n == 0 && tab->pnt && tab->prc == 0 && tab->wdt)
		tab->tl += ft_printf_putchar(' ');
	else if (!(n == 0 && tab->pnt && tab->prc == 0))
		tab->tl += ft_printf_puthex(n, upper);
	if (tab->dash)
		ft_padding(tab, len, 0);
}
