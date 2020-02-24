/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:39:54 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 15:33:52 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*dest_char;
	const unsigned char		*src_char;

	dest_char = (unsigned char*)dest;
	src_char = (unsigned char*)src;
	if (src_char == NULL && dest_char == NULL)
		return (NULL);
	if (src_char == NULL || dest_char == NULL)
		dest--;
	if (src_char < dest_char)
	{
		i = 1;
		while (i <= len)
		{
			dest_char[len - i] = src_char[len - i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			*(dest_char++) = *(src_char++);
	}
	return (dest);
}
