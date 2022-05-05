/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:13:06 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:41:51 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	ft_init_tab(t_print *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sp = 0;
	tab->sign = 0;
	tab->sharp = 0;
	tab->wdt = 0;
	tab->prc = 0;
	tab->tl = 0;
}

static int	is_conversion(char const *format, int pos)
{
	while (format[pos] && ft_strchr("-.# +*0123456789", format[pos]))
		pos++;
	if (ft_strchr("cspdiuxX%", format[pos]))
		return (1);
	return (0);
}

int	ft_printf(char const *format, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	tab = (t_print *) malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%' && is_conversion(format, i + 1))
		{
			i = ft_printf_eval_format(tab, format, i + 1);
			ret += tab->tl;
			ft_init_tab(tab);
		}
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	free(tab);
	return (ret);
}
