/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:27:26 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/19 15:32:08 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*trmd;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len != 0)
		while (s1[i + len - 1]
				&& ft_strchr(set, s1[i + len - 1]) != NULL)
			len--;
	if ((trmd = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	trmd = ft_strncpy(trmd, &s1[i], len);
	trmd[len] = '\0';
	return (trmd);
}