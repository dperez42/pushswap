/* ************************************************************************** */
#include "pushswap.h"

// Move all number in stack2 to stack1
int	ft_move_b_a(t_list **stack1, t_list **stack2, int debug)
{
	t_list	*tmp;
	int		dim;
	int		i;

	i = 0;
	dim = ft_lstsize(*stack2);
	while (i < dim)
	{
		ft_push_a(stack2, stack1, debug);
		i ++;
	}
	return (i);
}

// Move best number to stack2 from stack1
int	ft_move_0(t_list **stack1, t_list **stack2, t_chunk *mychunks, int i)
{
	t_moves		moves;
	int			cmd;

	cmd = 0;
	moves = ft_move_elem(mychunks[i], stack1, stack2);
	if (moves.method == 10)
		cmd = cmd + ft_method_1_0(stack1, stack2, moves, 0);
	if (moves.method == 11)
		cmd = cmd + ft_method_1_1(stack1, stack2, moves, 0);
	if (moves.method == 40)
		cmd = cmd + ft_method_4_0(stack1, stack2, moves, 0);
	if (moves.method == 41)
		cmd = cmd + ft_method_4_1(stack1, stack2, moves, 0);
	if (moves.method == 20)
		cmd = cmd + ft_method_2_0(stack1, stack2, moves, 0);
	if (moves.method == 30)
		cmd = cmd + ft_method_3_0(stack1, stack2, moves, 0);
	return (cmd);
}

// Move best number to stack2 from stack1
int	ft_move_1(t_list **stack1, t_list **stack2, t_chunk *mychunks, int i)
{
	t_moves		moves;
	int			cmd;

	cmd = 0;
	moves = ft_move_elem(mychunks[i], stack1, stack2);
	if (moves.method == 10)
		cmd = cmd + ft_method_1_0(stack1, stack2, moves, 1);
	if (moves.method == 11)
		cmd = cmd + ft_method_1_1(stack1, stack2, moves, 1);
	if (moves.method == 40)
		cmd = cmd + ft_method_4_0(stack1, stack2, moves, 1);
	if (moves.method == 41)
		cmd = cmd + ft_method_4_1(stack1, stack2, moves, 1);
	if (moves.method == 20)
		cmd = cmd + ft_method_2_0(stack1, stack2, moves, 1);
	if (moves.method == 30)
		cmd = cmd + ft_method_3_0(stack1, stack2, moves, 1);
	return (cmd);
}

// Short print orders
int	ft_short_v2(t_list **stack1, t_list **stack2, int nb_chunks, int *nbstack)
{
	int			cmd;
	int			i;
	t_chunk		*mychunks;

	mychunks = ft_mychunks(stack1, stack2, nb_chunks, nbstack);
	i = nb_chunks;
	cmd = 0;
	while (i > 0)
	{
		while (1)
		{
			if (!ft_check_nb(mychunks[i], *stack1))
				break ;
			cmd = cmd + ft_move_1(stack1, stack2, mychunks, i);
		}
		if (i == nb_chunks)
			cmd = cmd + ft_order_stack2_1(stack1, stack2, mychunks, i);
		if (i < nb_chunks)
			cmd = cmd + ft_order_stacks_1(stack1, stack2, mychunks, i);
		cmd = cmd + ft_move_b_a(stack1, stack2, 1);
		i--;
	}
	free(mychunks);
	return (cmd);
}

// Short without print orders
int	ft_short_v1(t_list **stack1, t_list **stack2, int nb_chunks, int *nbstack)
{
	int		cmd;
	int		i;
	t_chunk	*mychunks;

	mychunks = ft_mychunks(stack1, stack2, nb_chunks, nbstack);
	i = nb_chunks;
	cmd = 0;
	while (i > 0)
	{
		while (1)
		{
			if (!ft_check_nb(mychunks[i], *stack1))
				break ;
			cmd = cmd + ft_move_0(stack1, stack2, mychunks, i);
		}
		if (i == nb_chunks)
			cmd = cmd + ft_order_stack2_0(stack1, stack2, mychunks, i);
		if (i < nb_chunks)
			cmd = cmd + ft_order_stacks_0(stack1, stack2, mychunks, i);
		cmd = cmd + ft_move_b_a(stack1, stack2, 0);
		i--;
	}
	free(mychunks);
	return (cmd);
}
