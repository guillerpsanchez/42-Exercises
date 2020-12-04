/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:27:14 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 11:39:27 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcft.h"

static	int		ft_size_itoa(int i)
{
	int		cont;

	cont = 0;
	if (i < 0)
		i = -i;
	while (i > 9)
	{
		i = i / 10;
		cont++;
	}
	cont++;
	return (cont);
}

char			*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*tab;

	i = ft_size_itoa(n);
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1 + neg))))
		return (NULL);
	if (neg)
		tab[0] = '-';
	tab[i + neg] = '\0';
	while (i)
	{
		tab[i - (neg ? 0 : 1)] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (tab);
}
