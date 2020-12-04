/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:40 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 11:56:44 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hexa_input(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	}
	count = count + ft_putstr(hex, ft_strlen(hex));
	return (count);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_hexa_input(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count = count + ft_width(flags.width, 0, 0);
	}
	else
	{
		count = count + ft_width(flags.width, ft_strlen(hex), flags.zero);
	}
	if (flags.minus == 0)
		count = count + ft_hexa_input(hex, flags);
	return (count);
}

int			ft_hexa(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count = count + ft_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl_base((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_str_tolower(hex);
	count = count + ft_put_hex(hex, flags);
	free(hex);
	return (count);
}

/*
** POINTER HANDLING
*/

static int	ft_input(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count = count + ft_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot, ft_strlen(pointer), 1);
		count = count + ft_putstr(pointer, flags.dot);
	}
	else
		count = count + ft_putstr(pointer, ft_strlen(pointer));
	return (count);
}

int			ft_pointer(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		if (flags.width >= 0 && flags.minus == 0)
			(((count = count + ft_width(flags.width - 2, 0, 0))
			|| 1) && ((count = count + ft_putstr("0x", 2)) || 1));
		else
			(((count = count + ft_putstr("0x", 2)) || 1) &&
			((count = count + ft_width(flags.width - 2, 0, 0)) || 1));
		return (count);
	}
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		count = count + ft_input(p, flags);
	count = count + ft_width(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count = count + ft_input(p, flags);
	free(p);
	return (count);
}
