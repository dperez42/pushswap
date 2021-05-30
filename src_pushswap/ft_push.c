/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:59 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:48:31 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_b(t_list **stacka, t_list **stackb, int debug)
{
	t_list	*tmp;

	if (!*stacka)
		return ;
	tmp = *stacka;
	*stacka = ft_erase(*stacka);
	ft_lstadd_front(stackb, ft_lstnew(tmp->nb));
	if (debug)
		write(1, "pb\n", 3);
	return ;
}

void	ft_push_a(t_list **stacka, t_list **stackb, int debug)
{
	t_list	*tmp;

	if (!*stacka)
		return ;
	tmp = *stacka;
	*stacka = ft_erase(*stacka);
	ft_lstadd_front(stackb, ft_lstnew(tmp->nb));
	if (debug)
		write(1, "pa\n", 3);
	return ;
}
