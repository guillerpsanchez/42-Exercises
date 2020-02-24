/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:27:24 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 13:41:09 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int					i;
	unsigned char		*dest_char;
	unsigned char		*src_char;
	unsigned char		d;
	void				*ret;

	d = (unsigned char)c;
	i = 0;
	dest_char = (unsigned char*)dest;
	src_char = (unsigned char*)src;
	while ((int)n > i)
	{
		dest_char[i] = src_char[i];
		if (dest_char[i] == d)
		{
			ret = dest + i + 1;
			return (ret);
		}
		i++;
	}
	return (NULL);
}
