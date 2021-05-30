/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:37:08 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:41:06 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_method_1_0(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_rotaty_a_nb(stack1, (moves.stacka_up - moves.stackb_up), debug);
	ft_rotaty_ab_nb(stack1, stack2, moves.stackb_up, debug);
	ft_push_b(stack1, stack2, debug);
	return (moves.stacka_up + 1);
}

int	ft_method_1_1(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_rotaty_b_nb(stack2, moves.stackb_up - moves.stacka_up, debug);
	ft_rotaty_ab_nb(stack1, stack2, moves.stacka_up, debug);
	ft_push_b(stack1, stack2, debug);
	return (moves.stackb_up + 1);
}

int	ft_method_2_0(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_rotaty_a_nb(stack1, moves.stacka_up, debug);
	ft_reversy_b_nb(stack2, moves.stackb_botton, debug);
	ft_push_b(stack1, stack2, debug);
	return (moves.stacka_up + moves.stackb_botton + 1);
}

int	ft_method_3_0(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_reversy_a_nb(stack1, moves.stacka_botton, debug);
	ft_rotaty_b_nb(stack2, moves.stackb_up, debug);
	ft_push_b(stack1, stack2, debug);
	return (moves.stacka_botton + moves.stackb_up + 1);
}
