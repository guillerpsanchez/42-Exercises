/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:33 by gpenaran          #+#    #+#             */
/*   Updated: 2019/11/21 13:53:43 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*next;

	if (!(list = *lst))
		return ;
	while (list)
	{
		next = list->next;
		del(list->content);
		free(list);
		list = next;
	}
	*lst = NULL;
}