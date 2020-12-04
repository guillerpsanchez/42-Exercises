/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:23:58 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 12:14:39 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_checkconversion(int recv_mod)
{
	if ((recv_mod == 'c') || (recv_mod == 's') || (recv_mod == 'p')
	|| (recv_mod == 'd') || (recv_mod == 'i') || (recv_mod == 'u')
	|| (recv_mod == 'x') || (recv_mod == 'X') || (recv_mod == '%'))
		return (1);
	else
		return (0);
	;
}

int	ft_isflag(int recv_flag)
{
	if ((recv_flag == '0') || (recv_flag == '*') || (recv_flag == '.')
	|| (recv_flag == '-'))
		return (1);
	else
		return (0);
	;
}

int	ft_handle(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_char(va_arg(args, int), flags);
	else if (c == '%')
		count = count + ft_percent(flags);
	else if (c == 'p')
		count = ft_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_int(va_arg(args, int), flags);
	else if (c == 'x')
		count = count + ft_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count = count + ft_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count = count + ft_uns_int((unsigned int)va_arg(args, unsigned int)
		, flags);
	return (count);
}

int	ft_width(int width, int minus, int zero)
{
	int count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width = width - 1;
		count++;
	}
	return (count);
}

int	ft_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_putstr("%", 1);
	count = count + ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count = count + ft_putstr("%", 1);
	return (count);
}
