/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:38:23 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/12 13:55:32 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] && s2[i] && k < n - 1)
	{
		i++;
		k++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
