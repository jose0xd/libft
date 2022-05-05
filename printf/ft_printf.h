/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:35:58 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/05 16:40:34 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_printf
{
	va_list	args;
	int		wdt;
	int		prc;
	int		dash;
	int		zero;
	int		pnt;
	int		sp;
	int		sign;
	int		sharp;
	int		tl;
}	t_print;

int		ft_printf(char const *format, ...);

int		ft_printf_eval_format(t_print *tab, char const *format, int pos);

int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s);
long	ft_printf_putsign(t_print *tab, long n);
int		ft_printf_putuns(unsigned int num);
int		ft_printf_puthex(unsigned long n, char upper);

void	ft_printf_char(t_print *tab);
void	ft_printf_string(t_print *tab);
void	ft_printf_porc(t_print *tab);

void	ft_printf_pointer(t_print *tab);
void	ft_printf_int(t_print *tab);
void	ft_printf_unsigned(t_print *tab);
void	ft_printf_hex(t_print *tab, char upper);

int		ft_printf_len_num(long n, int base);
char	ft_printf_getsign(t_print *tab, long n);
int		ft_printf_fill(char c, int len);

#endif
