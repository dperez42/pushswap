/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:29:00 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:29:04 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// check is a number of the chunk is in lst
int	ft_check_nb(t_chunk mychunks, t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->nb >= mychunks.nb_min && tmp->nb <= mychunks.nb_max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// distance of a number to the start of the lst
int	ft_distance_nb(t_list *lst, int nb)
{
	int		cont;

	cont = 0;
	if (!lst)
		return (cont);
	while (lst)
	{
		if (nb == lst->nb)
			return (cont);
		lst = lst->next;
		cont ++;
	}
	return (cont);
}

// position of a number to the start of the list
int	ft_distanceB_nb(t_list *lst, int nb)
{
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	if (!lst)
		return (cont);
	while (lst)
	{
		if (lst->next != 0 && (lst->next->nb > lst->nb)
			&& ((lst->next->nb < nb) || (lst->nb > nb)))
		{
			cont = i + 1;
			break ;
		}
		if (lst->next != 0 && (nb > lst->next->nb && nb < lst->nb))
		{
			cont = i + 1;
			break ;
		}
		lst = lst->next;
		i ++;
	}
	return (cont);
}

// distance of a number to the end of a lst
int	ft_distance_nb_end(t_list *lst, int nb)
{
	return ((ft_lstsize(lst) - ft_distance_nb(lst, nb)));
}

// position of a number to the end of a lst
int	ft_distanceB_nb_end(t_list *lst, int nb)
{
	return ((ft_lstsize(lst) - ft_distanceB_nb(lst, nb)));
}
