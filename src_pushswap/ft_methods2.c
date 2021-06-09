/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_methods2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:50:01 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/01 09:50:03 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_method_1(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_rotaty_a_nb(stack1, (moves.stacka_up - moves.stackb_up), debug);
	ft_rotaty_ab_nb(stack1, stack2, moves.stackb_up, debug);
	return (moves.stacka_up);
}

int	ft_method_2(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_rotaty_b_nb(stack2, moves.stackb_up - moves.stacka_up, debug);
	ft_rotaty_ab_nb(stack1, stack2, moves.stacka_up, debug);
	return (moves.stackb_up);
}

int	ft_method_3(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_rotaty_a_nb(stack1, moves.stacka_up, debug);
	ft_reversy_b_nb(stack2, moves.stackb_botton, debug);
	return (moves.stacka_up + moves.stackb_botton);
}

int	ft_method_4(t_list **stack1, t_list **stack2, t_moves moves, int debug)
{
	ft_reversy_a_nb(stack1, moves.stacka_botton, debug);
	ft_rotaty_b_nb(stack2, moves.stackb_up, debug);
	return (moves.stacka_botton + moves.stackb_up);
}
