/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:20:20 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 11:45:40 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}

static int	ft_input(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count = count + ft_width(flags.dot, ft_strlen(str), 0);
		count = count + ft_putstr(str, flags.dot);
	}
	else
		count = count + ft_putstr(str, ft_strlen(str));
	return (count);
}

int			ft_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count = count + ft_input(str, flags);
	if (flags.dot >= 0)
		count = count + ft_width(flags.width, flags.dot, 0);
	else
		count = count + ft_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count = count + ft_input(str, flags);
	return (count);
}
