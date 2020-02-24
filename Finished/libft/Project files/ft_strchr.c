/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:46:38 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 14:19:11 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_char;

	s_char = (char*)s;
	while (*s_char != c)
	{
		if (*s_char == '\0')
			return (NULL);
		s_char++;
	}
	return (s_char);
}
