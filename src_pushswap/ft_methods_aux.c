/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:47:40 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/01 09:48:52 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_method_4_0(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_reversy_a_nb(stack1, (moves.stacka_botton - moves.stackb_botton), debug);
	ft_reversy_ab_nb(stack1, stack2, moves.stackb_botton, debug);
	ft_push_b(stack1, stack2, debug);
	return (moves.stacka_botton + 1);
}

int	ft_method_4_1(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_reversy_b_nb(stack2, (moves.stackb_botton - moves.stacka_botton), debug);
	ft_reversy_ab_nb(stack1, stack2, moves.stacka_botton, debug);
	ft_push_b(stack1, stack2, debug);
	return (moves.stackb_botton + 1);
}
