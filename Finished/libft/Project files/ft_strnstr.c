/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:14:11 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 13:55:18 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int i;
	unsigned int j;

	if (!*to_find)
	{
		return ((char*)str);
	}
	i = 0;
	while ((size_t)i < len && str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] != '\0' && str[i + j] == to_find[j] &&
			(size_t)j + (size_t)i < len)
				j++;
			if (to_find[j] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
