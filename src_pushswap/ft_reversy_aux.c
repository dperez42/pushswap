/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversy_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:33:34 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 09:33:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_reversy_b(t_list **lst, int debug)
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
		write(1, "rrb\n", 4);
	return ;
}

void	ft_reversy_b_2(t_list **lst)
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

void	ft_reversy_b_nb(t_list **lst, int nb, int debug)
{
	int	i;

	if (nb <= 0)
		return ;
	i = 0;
	while (i < nb)
	{
		ft_reversy_b(lst, debug);
		i++;
	}
	return ;
}
