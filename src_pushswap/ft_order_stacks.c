/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:41:29 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:46:43 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//Choose method to order stacks
int	ft_choose_method2(t_moves tmp)
{
	tmp.method = 1;
	if (tmp.stacka_up <= tmp.stacka_botton)
	{
		if (tmp.stacka_up >= tmp.stackb_up)
			tmp.method = 1;
		else
		{
			tmp.method = 3;
			if (tmp.stackb_up - tmp.stacka_up <= tmp.stackb_botton)
				tmp.method = 2;
		}
	}
	else
	{
		if (tmp.stacka_botton >= tmp.stackb_botton)
			tmp.method = 5;
		else
		{
			tmp.method = 4;
			if (tmp.stackb_botton - tmp.stackb_up <= tmp.stackb_botton)
				tmp.method = 6;
		}
	}
	return (tmp.method);
}

//Order chunks in stack A (- to +) y Stack B (+ to -)
int	ft_order_stacks_0(t_list **stack1, t_list **stack2, t_chunk *mychunks,
	int i)
{
	int		z;
	t_moves	tmp;

	tmp.stacka_up = ft_distance_nb(*stack1, mychunks[i + 1].nb_min);
	tmp.stacka_botton = ft_distance_nb_end(*stack1, mychunks[i + 1].nb_min);
	tmp.stackb_up = ft_distance_nb(*stack2, mychunks[i].nb_max);
	tmp.stackb_botton = ft_distance_nb_end(*stack2, mychunks[i].nb_max);
	if (ft_lstsize(*stack1) == 0)
		return (ft_order_stack2_0(stack1, stack2, mychunks, i));
	z = ft_choose_method2(tmp);
	if (z == 1)
		return (ft_method_1(stack1, stack2, tmp, 0));
	if (z == 2)
		return (ft_method_2(stack1, stack2, tmp, 0));
	if (z == 3)
		return (ft_method_3(stack1, stack2, tmp, 0));
	if (z == 4)
		return (ft_method_4(stack1, stack2, tmp, 0));
	if (z == 5)
		return (ft_method_5(stack1, stack2, tmp, 0));
	if (z == 6)
		return (ft_method_6(stack1, stack2, tmp, 0));
	return (1);
}

//order chunks in stack A (- to +) y Stack B (+ to -)
int	ft_order_stacks_1(t_list **stack1, t_list **stack2, t_chunk *mychunks,
	int i)
{
	int		z;
	t_moves	tmp;

	tmp.stacka_up = ft_distance_nb(*stack1, mychunks[i + 1].nb_min);
	tmp.stacka_botton = ft_distance_nb_end(*stack1, mychunks[i + 1].nb_min);
	tmp.stackb_up = ft_distance_nb(*stack2, mychunks[i].nb_max);
	tmp.stackb_botton = ft_distance_nb_end(*stack2, mychunks[i].nb_max);
	if (ft_lstsize(*stack1) == 0)
		return (ft_order_stack2_1(stack1, stack2, mychunks, i));
	z = ft_choose_method2(tmp);
	if (z == 1)
		return (ft_method_1(stack1, stack2, tmp, 1));
	if (z == 2)
		return (ft_method_2(stack1, stack2, tmp, 1));
	if (z == 3)
		return (ft_method_3(stack1, stack2, tmp, 1));
	if (z == 4)
		return (ft_method_4(stack1, stack2, tmp, 1));
	if (z == 5)
		return (ft_method_5(stack1, stack2, tmp, 1));
	if (z == 6)
		return (ft_method_6(stack1, stack2, tmp, 1));
	return (0);
}

//Order chunks in Stack B (+ to -) in first pass
int	ft_order_stack2_0(t_list **stack1, t_list **stack2, t_chunk *mychunks,
	int i)
{
	int	cmd;
	int	nb;
	int	nb_end;

	cmd = 0;
	nb = ft_distance_nb(*stack2, mychunks[i].nb_max);
	nb_end = ft_distance_nb_end(*stack2, mychunks[i].nb_max);
	if (nb <= nb_end)
	{
		cmd = cmd + nb;
		ft_rotaty_b_nb(stack2, nb, 0);
	}
	else
	{
		cmd = cmd + nb;
		ft_reversy_b_nb(stack2, nb_end, 0);
	}
	return (cmd);
}

//Order chunks in Stack B (+ to -) in first pass
int	ft_order_stack2_1(t_list **stack1, t_list **stack2, t_chunk *mychunks,
	int i)
{
	int	cmd;
	int	nb;
	int	nb_end;

	cmd = 0;
	nb = ft_distance_nb(*stack2, mychunks[i].nb_max);
	nb_end = ft_distance_nb_end(*stack2, mychunks[i].nb_max);
	if (nb <= nb_end)
	{
		cmd = cmd + nb;
		ft_rotaty_b_nb(stack2, nb, 1);
	}
	else
	{
		cmd = cmd + nb;
		ft_reversy_b_nb(stack2, nb_end, 1);
	}
	return (cmd);
}
