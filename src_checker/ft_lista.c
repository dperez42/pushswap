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

#include "checker.h"

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
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i = i + 1;
	}
	return (i);
}

void	ft_rotatyAll(t_list **stackA, t_list **stackB)
{
	ft_rotatyT(stackA);
	ft_rotatyT(stackB);
	return ;
}
