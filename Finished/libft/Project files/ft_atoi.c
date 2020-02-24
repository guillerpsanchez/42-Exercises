/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:03:55 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 13:27:16 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int cont;
	int signo;
	int ret;

	cont = 0;
	signo = 1;
	ret = 0;
	while (str[cont] && (str[cont] == ' ' || str[cont] == '\n' ||
	str[cont] == '\t' || str[cont] == '\v' || str[cont] == '\f' ||
	str[cont] == '\r'))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			signo = -1;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		ret = (ret * 10) + (str[cont] - 48);
		cont++;
	}
	return (ret * signo);
}
