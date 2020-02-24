/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:42:50 by gpenaran          #+#    #+#             */
/*   Updated: 2019/09/13 10:22:11 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[k])
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
