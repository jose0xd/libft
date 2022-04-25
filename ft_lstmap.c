/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:27:55 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/25 17:33:52 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	node = new_lst;
	while (lst->next)
	{
		node->next = ft_lstnew(f(lst->next->content));
		if (node->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (new_lst);
}
