/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:38:57 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:28:07 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Check is lst is short
int	ft_check(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		if (lst->nb > lst->next->nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

//Check is lst is inver short
int	ft_check_inv(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		if (lst->nb < lst->next->nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	*ft_load_stack_array(t_list *lst)
{
	int	i;
	int	*dst;
	int	f;
	int	p;

	i = 0;
	dst = malloc((sizeof(int) * ft_lstsize(lst)));
	while (1)
	{
		dst[i] = lst->nb;
		lst = lst->next;
		i = i + 1;
		if (!lst)
			break ;
	}
	return (dst);
}

int	*ft_short_array(int *src, int l)
{
	int	i;
	int	f;
	int	p;

	f = 1;
	p = src[0];
	while (f == 1)
	{
		i = 0;
		f = 0;
		while (i < l - 1)
		{
			if (src[i] > src[i + 1])
			{
				p = src[i + 1];
				src[i + 1] = src[i];
				src[i] = p;
				f = 1;
			}
			i ++;
		}
	}
	return (src);
}

int	ft_check_both(t_list **stack1, t_list **stack2)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stack1;
	tmp2 = *stack2;
	if (!tmp1)
		return (0);
	if (!tmp2)
		return (1);
	if (!ft_check(*stack1) && !ft_check_inv(*stack2))
		return (0);
	return (1);
}
