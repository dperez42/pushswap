/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:41:50 by dperez-z          #+#    #+#             */
/*   Updated: 2021/04/13 10:21:27 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swapT(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*lst) < 2)
		return ;
	first = *lst;
	second = first->next;
	if (!first->next)
		return ;
	first->next = second->next;
	second->next = first;
	*lst = second;
	return ;
}

void	ft_swapAll(t_list **stackA, t_list **stackB)
{
	ft_swapT (stackA);
	ft_swapT (stackB);
	return ;
}

void	ft_reversyT(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*prevlast;

	if (!*lst)
		return ;
	last = *lst;
	first = *lst;
	while (last->next)
	{
		prevlast = last;
		last = last->next;
	}
	prevlast->next = NULL;
	last->next = first;
	*lst = last;
	return ;
}

void	ft_reversyAll(t_list **stackA, t_list **stackB)
{
	ft_reversyT (stackA);
	ft_reversyT (stackB);
	return ;
}

void	ft_rotatyT(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!*lst)
		return ;
	last = *lst;
	if (!last->next)
		return ;
	second = last->next;
	first = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*lst = second;
	return ;
}
