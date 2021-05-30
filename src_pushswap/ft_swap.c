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

#include "pushswap.h"

void	ft_swap_a(t_list **lst)
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
	write (1, "sa\n", 3);
	return ;
}

void	ft_swap_b(t_list **lst)
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
	write (1, "sb\n", 3);
	return ;
}

void	ft_swap_ab(t_list **stacka, t_list **stackb)
{
	ft_swap_a (stacka);
	ft_swap_b (stackb);
	return ;
}
