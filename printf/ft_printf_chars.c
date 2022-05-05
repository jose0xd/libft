/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:19:59 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:44:43 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_printf_char(t_print *tab)
{
	char	c;
	int		i;
	char	pad;

	pad = ' ';
	if (tab->zero && !tab->dash)
		pad = '0';
	c = va_arg(tab->args, int);
	if (tab->dash)
		ft_printf_putchar(c);
	i = 0;
	while (i++ < tab->wdt - 1)
	{
		ft_printf_putchar(pad);
		tab->tl++;
	}
	if (!tab->dash)
		ft_printf_putchar(c);
	tab->tl++;
}

void	ft_printf_string(t_print *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	if (tab->pnt)
		str = ft_substr(str, 0, tab->prc);
	len = ft_strlen(str);
	if (tab->dash)
		tab->tl += ft_printf_putstr(str);
	while (len++ < tab->wdt)
	{
		ft_printf_putchar(' ');
		tab->tl++;
	}
	if (!tab->dash)
		tab->tl += ft_printf_putstr(str);
	if (tab->pnt)
		free(str);
}

void	ft_printf_porc(t_print *tab)
{
	int		i;
	char	pad;

	pad = ' ';
	if (tab->zero && !tab->dash)
		pad = '0';
	if (tab->dash)
		ft_printf_putchar('%');
	i = 0;
	while (i++ < tab->wdt - 1)
	{
		ft_printf_putchar(pad);
		tab->tl++;
	}
	if (!tab->dash)
		ft_printf_putchar('%');
	tab->tl++;
}
