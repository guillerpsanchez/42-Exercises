/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:00:39 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 13:45:26 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*chr;

	chr = (unsigned char*)s;
	i = 0;
	while (i < (int)n)
	{
		if (chr[i] == (unsigned char)c)
		{
			return ((void *)&chr[i]);
		}
		i++;
	}
	return (NULL);
}
