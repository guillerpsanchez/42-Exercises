/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:31:18 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 13:32:20 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dest;
	if (!n || dest == src)
	{
		return (dest);
	}
	while (n)
	{
		*s2 = *s1;
		s1++;
		s2++;
		n--;
	}
	return (dest);
}
