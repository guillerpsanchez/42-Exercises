/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:32:29 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 14:18:36 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int tam;

	tam = ft_strlen((char*)s);
	while (s[tam] != c && tam != 0)
	{
		tam--;
	}
	if (s[tam] == c)
	{
		return ((char*)&s[tam]);
	}
	return (NULL);
}
