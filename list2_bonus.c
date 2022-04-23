/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:41:19 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/23 13:41:21 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL)
		return ;
	next = (*lst)->next;
	while (next)
	{
		ft_lstdelone(*lst, del);
		*lst = next;
		next = (*lst)->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

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
