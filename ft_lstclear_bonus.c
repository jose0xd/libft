/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:26:13 by jarredon          #+#    #+#             */
/*   Updated: 2022/04/24 12:26:34 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
