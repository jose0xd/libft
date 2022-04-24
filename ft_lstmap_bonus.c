/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:27:55 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:28:10 by jarredon         ###   ########.fr       */
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
	new_lst = ft_lstnew(NULL);
	node = new_lst;
	while (lst)
	{
		node->content = f(lst->content);
		node->next = ft_lstnew(NULL);
		node = node->next;
		lst = lst->next;
	}
	free(node);
	(void) del;
	node = NULL;
	return (new_lst);
}
