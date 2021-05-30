/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lista.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:35:03 by dperez-z          #+#    #+#             */
/*   Updated: 2021/04/13 09:41:31 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_erase(t_list *lst)
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL)
		return (lst);
	first = lst;
	second = lst->next;
	free (lst);
	lst = NULL;
	lst = second;
	return (lst);
}

t_list	*ft_add_first(t_list *Stack, t_list *Node)
{
	t_list	*tmp;

	tmp = ft_lstnew(Node->nb);
	ft_lstadd_front(&Stack, tmp);
	return (Stack);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*list_ptr;

	new->next = NULL;
	if (*alst)
	{
		list_ptr = new;
		if (list_ptr)
		{
			list_ptr->next = (*alst);
			(*alst) = list_ptr;
		}
	}
	else
		*alst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = i + 1;
		lst = lst->next;
	}
	return (i);
}
