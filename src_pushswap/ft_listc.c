/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:35:56 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:36:48 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstprint(t_list *lst)
{
	t_list	*list_ptr;
	int		i;

	i = 0;
	list_ptr = lst;
	while (list_ptr)
	{
		printf("%i \n", list_ptr->nb);
		list_ptr = list_ptr->next;
		i++;
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

void	ft_delete_list(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
