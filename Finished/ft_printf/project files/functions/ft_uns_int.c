/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:23:39 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 12:13:46 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_input(char *u_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count = count + ft_width(flags.dot - 1, ft_strlen(u_num) - 1, 1);
	count = count + ft_putstr(u_num, ft_strlen(u_num));
	return (count);
}

static int	ft_put_uns_int(char *u_num, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count = count + ft_input(u_num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count = count + ft_width(flags.width, 0, 0);
	}
	else
		count = count + ft_width(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		count = count + ft_input(u_num, flags);
	return (count);
}

int			ft_uns_int(unsigned int number, t_flags flags)
{
	int		count;
	char	*u_num;

	count = 0;
	number = (unsigned int)(4294967295 + 1 + number);
	if (flags.dot == 0 && number == 0)
	{
		count = count + ft_width(flags.width, 0, 0);
		return (count);
	}
	u_num = ft_u_itoa(number);
	count = ft_put_uns_int(u_num, flags);
	free(u_num);
	return (count);
}
