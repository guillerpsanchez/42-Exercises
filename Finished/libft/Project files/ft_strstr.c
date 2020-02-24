/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:43:25 by gpenaran          #+#    #+#             */
/*   Updated: 2019/09/16 14:42:50 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int lenght;
	int i;
	int j;

	lenght = 0;
	i = 0;
	j = 0;
	while (to_find[lenght] != '\0')
		lenght++;
	if (lenght == 0)
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && j < lenght)
			j++;
		if (j == lenght)
			return (&str[i]);
		i++;
	}
	return (0);
}
