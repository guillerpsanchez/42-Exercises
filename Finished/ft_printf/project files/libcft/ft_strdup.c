/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:33:21 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 11:48:31 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcft.h"

char	*ft_strdup(const char *s)
{
	char	*s_char;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(s_char = malloc(sizeof(char) * (i + 1))))
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		s_char[i] = s[i];
		i++;
	}
	s_char[i] = '\0';
	return (s_char);
}
