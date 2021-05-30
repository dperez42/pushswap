/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:21:48 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/20 09:17:57 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("%i \n", lst->nb);
		lst = lst->next;
		i = i + 1;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->nb = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lastitem(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_pushT(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;

	if (ft_lstsize(*stackA) < 1)
		return ;
	tmp = *stackA;
	*stackA = ft_erase(*stackA);
	*stackB = ft_add_first(*stackB, tmp);
	return ;
}
