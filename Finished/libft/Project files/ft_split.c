/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:14:12 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/21 10:24:58 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter(char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			k = 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				j++;
		}
		else
			i++;
	}
	return (j + k);
}

static	char	*ft_allocate(char const *s, char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(tab, s, i + 1);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = -1;
	if (!s)
		return (NULL);
	j = ft_counter(s, c);
	if (!(tab = malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (++i < j)
	{
		while (s[0] == c)
			s++;
		if (!(tab[i] = ft_allocate(s, c)))
		{
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		s += ft_strlen(tab[i]);
	}
	tab[i] = 0;
	return (tab);
}