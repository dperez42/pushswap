/* ************************************************************************** */
#include "pushswap.h"

//Make partitions
t_chunk	*ft_mychunks(t_list **stack1, t_list **stack2, int nb_chunks,
	int *nbstack)
{
	t_chunk	*mychunks;
	int		i;
	int		dim;

	mychunks = malloc (sizeof(t_chunk) * (nb_chunks + 1));
	dim = ft_lstsize(*stack1) / nb_chunks;
	i = nb_chunks;
	while (i > 1)
	{
		mychunks[i].dim = dim;
		mychunks[i].nb_min = nbstack[ft_lstsize(*stack1)
			- (nb_chunks - i + 1) * dim];
		mychunks[i].nb_max = nbstack[ft_lstsize(*stack1)
			- (nb_chunks - i) * dim - 1];
		i--;
	}
	mychunks[i].dim = ft_lstsize(*stack1) - (nb_chunks - 1) * dim;
	mychunks[i].nb_min = nbstack[0];
	mychunks[i].nb_max = nbstack[ft_lstsize(*stack1)
		- (nb_chunks - i) * dim - 1];
	return (mychunks);
}

// Analize best movement between remain numbers of a partition in lst 
t_moves	ft_move_elem(t_chunk mychunk, t_list **stack1, t_list **stack2)
{
	t_list		*lst;
	t_moves		allmoves;
	int			nb_moves;
	t_moves		bestmov;

	nb_moves = 100000000;
	lst = *stack1;
	while (lst)
	{
		if (lst->nb >= mychunk.nb_min && lst->nb <= mychunk.nb_max)
		{
			allmoves.nb = lst->nb;
			allmoves.stacka_up = ft_distance_nb(*stack1, lst->nb);
			allmoves.stacka_botton = ft_distance_nb_end(*stack1, lst->nb);
			allmoves.stackb_up = ft_distanceB_nb(*stack2, lst->nb);
			allmoves.stackb_botton = ft_distanceB_nb_end(*stack2, lst->nb);
			if (ft_nb_moves(allmoves).tot <= nb_moves)
			{
				bestmov = ft_nb_moves(allmoves);
				nb_moves = bestmov.tot;
			}
		}
		lst = lst->next;
	}
	return (bestmov);
}

t_moves	ft_nb_moves_1(t_moves mov)
{
	t_moves	dst;

	dst.stacka_up = mov.stacka_up;
	dst.stacka_botton = mov.stacka_botton;
	dst.stackb_up = mov.stackb_up;
	dst.stackb_botton = mov.stackb_botton;
	if (mov.stacka_up >= mov.stackb_up)
	{
		dst.tot = 2 * dst.stacka_up + 1;
		dst.method = 10;
	}
	else
	{
		if (mov.stackb_up - mov.stacka_up < mov.stackb_botton)
		{
			dst.tot = 2 * dst.stackb_up + 1;
			dst.method = 11;
		}
		else
		{
			dst.tot = dst.stacka_up + dst.stackb_botton + 1;
			dst.method = 20;
		}
	}
	return (dst);
}

t_moves	ft_nb_moves_2(t_moves mov)
{
	t_moves	dst;

	dst.stacka_up = mov.stacka_up;
	dst.stacka_botton = mov.stacka_botton;
	dst.stackb_up = mov.stackb_up;
	dst.stackb_botton = mov.stackb_botton;
	if (mov.stacka_botton > mov.stackb_botton)
	{
		dst.tot = 2 * dst.stacka_botton + 1;
		dst.method = 40;
	}
	else
	{
		if (mov.stackb_botton - mov.stacka_botton < mov.stackb_up)
		{
			dst.tot = 2 * dst.stackb_botton + 1;
			dst.method = 41;
		}
		else
		{
			dst.tot = dst.stacka_botton + dst.stackb_up + 1;
			dst.method = 30;
		}
	}
	return (dst);
}

// Calc number of moves and method of a movement
t_moves	ft_nb_moves(t_moves mov)
{
	t_moves	best;

	if (mov.stacka_up <= mov.stacka_botton)
		best = ft_nb_moves_1(mov);
	else
		best = ft_nb_moves_2(mov);
	best.nb = mov.nb;
	return (best);
}
