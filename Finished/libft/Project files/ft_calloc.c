/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:14:18 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/18 17:17:48 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (!(ptr = (unsigned char *)malloc(sizeof(size) * nmemb)))
		return (NULL);
	ft_memset(ptr, 0, nmemb);
	return ((void *)ptr);
}
