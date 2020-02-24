/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:05:43 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/14 16:15:31 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1_ucc;
	const unsigned char *s2_ucc;

	s1_ucc = (unsigned const char*)s1;
	s2_ucc = (unsigned const char*)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		s2--;
	while (n)
	{
		if (*s1_ucc != *s2_ucc)
		{
			return (*s1_ucc - *s2_ucc);
		}
		s1_ucc++;
		s2_ucc++;
		n--;
	}
	return (0);
}
