/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:23:43 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/21 10:17:09 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	int				cnt;
	unsigned int	res;

	res = 0;
	while (src[res] != '\0')
		res++;
	cnt = 0;
	while (src[cnt] != '\0' && cnt < ((int)size - 1))
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	if (size)
		dest[cnt] = '\0';
	return (res);
}
