/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:29:04 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 15:23:40 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	z;
	char			*str1;
	size_t			i;

	str1 = str;
	z = c;
	i = 0;
	while (i < len)
	{
		str1[i] = z;
		i++;
	}
	return (str1);
}
