/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:27:48 by ekrebs            #+#    #+#             */
/*   Updated: 2023/11/29 17:09:44 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_iteration(t_list *src, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*iterated_link;
	void	*iteration;

	iteration = (*f)(src->content);
	iterated_link = ft_lstnew(iteration);
	if (!iteration || !iterated_link)
	{
		free(iterated_link);
		(*del)(iteration);
		return (NULL);
	}
	return (iterated_link);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	first = ft_create_iteration(lst, f, del);
	if (!first)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new = ft_create_iteration(lst, f, del);
		if (!new)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
	}
	return (first);
}
