/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:43:36 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/19 17:43:54 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (s == NULL)
		return (NULL);
	if (!(mapped = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(mapped + i) = (*f)(i, *(s + i));
		i++;
	}
	*(mapped + i) = '\0';
	return (mapped);
}
