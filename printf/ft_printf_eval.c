/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:19:41 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:45:28 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static void	ft_get_precision(t_print *tab, char const *format, int *pos)
{
	tab->pnt = 1;
	if (format[(*pos) + 1] == '*')
		tab->prc = va_arg(tab->args, int);
	else
		tab->prc = ft_atoi(&format[*pos + 1]);
	while (ft_isdigit(format[++(*pos)]))
		;
	(*pos)--;
}

static void	ft_get_width(t_print *tab, char const *format, int *pos)
{
	if (format[*pos] == '*' && tab->pnt)
		return ;
	if (format[*pos] == '*')
	{
		tab->wdt = va_arg(tab->args, int);
		if (tab->wdt < 0)
		{
			tab->dash = 1;
			tab->wdt = -tab->wdt;
		}
	}
	else
		tab->wdt = ft_atoi(&format[*pos]);
	while (ft_isdigit(format[++(*pos)]))
		;
	(*pos)--;
}

static void	ft_print(t_print *tab, char type)
{
	if (type == 'c')
		ft_printf_char(tab);
	else if (type == 's')
		ft_printf_string(tab);
	else if (type == 'p')
		ft_printf_pointer(tab);
	else if (type == 'd' || type == 'i')
		ft_printf_int(tab);
	else if (type == 'u')
		ft_printf_unsigned(tab);
	else if (type == 'x')
		ft_printf_hex(tab, 0);
	else if (type == 'X')
		ft_printf_hex(tab, 1);
	else if (type == '%')
		ft_printf_porc(tab);
}

int	ft_printf_eval_format(t_print *tab, char const *format, int pos)
{
	while (!ft_strchr("cspdiuxX%", format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		else if (format[pos] == '0')
			tab->zero = 1;
		else if (format[pos] == '.')
			ft_get_precision(tab, format, &pos);
		else if (format[pos] == ' ')
			tab->sp = 1;
		else if (format[pos] == '+')
			tab->sign = 1;
		else if (format[pos] == '#')
			tab->sharp = 1;
		else
			ft_get_width(tab, format, &pos);
		pos++;
	}
	ft_print(tab, format[pos]);
	return (pos);
}
