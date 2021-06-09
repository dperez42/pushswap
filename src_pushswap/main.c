/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:40:24 by dperez-z          #+#    #+#             */
/*   Updated: 2021/04/09 10:42:25 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_short_35(t_list *stack1, t_list *stack2)
{
	int		nb;
	int		*nbstack;

	nb = ft_lstsize(stack1);
	if (nb == 3)
	{
		ft_short_v3(&stack1, &stack2);
		exit(0);
	}
	if (nb == 5)
	{
		nbstack = ft_load_stack_array(stack1);
		nbstack = ft_short_array(nbstack, ft_lstsize(stack1));
		nb = ft_lstsize(stack1);
		ft_short_v5(&stack1, &stack2, nbstack);
		free(nbstack);
		exit (0);
	}
	return ;
}

int	ft_nb_chunk(int narg, char **argv, t_list *stacka, int *nbstack)
{
	int		j;
	int		cmd;
	int		cmdprev;
	int		ch;
	t_list	*stackb;

	j = ft_lstsize(stacka) / 10;
	cmd = 1000000000;
	cmdprev = 0 ;
	ch = 0;
	while (j > 0)
	{
		stacka = NULL;
		stackb = NULL;
		ft_check_all_args(narg, argv, &stacka);
		cmdprev = ft_short_v1(&stacka, &stackb, j, nbstack);
		if (cmdprev < cmd)
		{
			ch = j;
			cmd = cmdprev;
		}
		ft_delete_list(&stacka);
		j --;
	}
	return (ch);
}

int	main(int narg, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		*nbstack;
	int		best_nb_chunks;

	stacka = NULL;
	stackb = NULL;
	ft_check_all_args(narg, argv, &stacka);
	if (!ft_check(stacka))
		ft_exit_ok();
	ft_short_35(stacka, stackb);
	nbstack = ft_load_stack_array(stacka);
	nbstack = ft_short_array(nbstack, ft_lstsize(stacka));
	best_nb_chunks = ft_nb_chunk(narg, argv, stacka, nbstack);
	ft_delete_list(&stacka);
	ft_check_all_args(narg, argv, &stacka);
	ft_short_v2(&stacka, &stackb, 1, nbstack);
	free(nbstack);
	return (0);
}
