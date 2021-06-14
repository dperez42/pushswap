/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotaty_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:33:43 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 09:33:44 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotaty_b_2(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!*lst || ft_lstsize(*lst) < 2)
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

void	ft_rotaty_b_nb(t_list **lst, int nb, int debug)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_rotaty_b(lst, debug);
		i++;
	}
	return ;
}

void	ft_rotaty_ab(t_list **stacka, t_list **stackb, int debug)
{
	ft_rotaty_a_2(stacka);
	ft_rotaty_b_2(stackb);
	if (debug)
		write(1, "rr\n", 3);
	return ;
}

void	ft_rotaty_ab_nb(t_list **stacka, t_list **stackb, int nb, int debug)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_rotaty_ab(stacka, stackb, debug);
		i++;
	}
	return ;
}
