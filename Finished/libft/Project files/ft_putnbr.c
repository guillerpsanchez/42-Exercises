/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:35:15 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/11 10:26:36 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		write(1, "-", 1);
		nbr = -1 * nb;
	}
	else
	{
		nbr = nb;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	nbr = nbr % 10 + 48;
	write(1, &nbr, 1);
}
