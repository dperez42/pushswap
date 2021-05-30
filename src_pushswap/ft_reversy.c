/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:48:54 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 13:06:43 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_reversy_a(t_list **lst, int debug)
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
	if (debug)
		write(1, "rra\n", 4);
	return ;
}

void	ft_reversy_a_2(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*prevlast;

	if (!*lst || ft_lstsize(*lst) < 2)
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

void	ft_reversy_a_nb(t_list **lst, int nb, int debug)
{
	int	i;

	if (nb <= 0)
		return ;
	i = 0;
	while (i < nb)
	{
		ft_reversy_a(lst, debug);
		i++;
	}
	return ;
}

void	ft_reversy_ab(t_list **stackA, t_list **stackB, int debug)
{
	ft_reversy_a_2 (stackA);
	ft_reversy_b_2 (stackB);
	if (debug)
		write(1, "rrr\n", 4);
	return ;
}

void	ft_reversy_ab_nb(t_list **stackA, t_list **stackB, int nb, int debug)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return ;
	while (i < nb)
	{
		ft_reversy_ab(stackA, stackB, debug);
		i++;
	}
	return ;
}
