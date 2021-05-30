#include "pushswap.h"

int	ft_short_v5(t_list **stack1, t_list **stack2, int *nbstack)
{
	int	i;
	int	nb;
	int	nb_end;

	i = 0;
	nb = ft_distance_nb(*stack1, nbstack[i]);
	nb_end = ft_distance_nb_end(*stack1, nbstack[i]);
	while (i < 2)
	{
		if (nb >= nb_end)
			ft_reversy_a_nb(stack1, ft_distance_nb_end(*stack1, nbstack[i]), 1);
		else
			ft_rotaty_a_nb(stack1, ft_distance_nb(*stack1, nbstack[i]), 1);
		ft_push_b(stack1, stack2, 1);
		i++;
	}
	ft_short_v3(stack1, stack2);
	ft_move_b_a(stack1, stack2, 1);
	return (0);
}

int	ft_short_v3(t_list **stack1, t_list **stack2)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = *stack1;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->nb < tmp2->nb && tmp2->nb > tmp3->nb && tmp1->nb < tmp3->nb)
	{
		ft_reversy_a(stack1, 1);
		ft_swap_a(stack1);
	}
	if (tmp1->nb < tmp2->nb && tmp2->nb > tmp3->nb && tmp1->nb > tmp3->nb)
		ft_reversy_a(stack1, 1);
	if (tmp1->nb > tmp2->nb && tmp2->nb < tmp3->nb && tmp1->nb < tmp3->nb)
		ft_swap_a(stack1);
	if (tmp1->nb > tmp2->nb && tmp2->nb > tmp3->nb && tmp1->nb > tmp3->nb)
	{
		ft_swap_a(stack1);
		ft_reversy_a(stack1, 1);
	}
	if (tmp1->nb > tmp2->nb && tmp2->nb < tmp3->nb && tmp1->nb > tmp3->nb)
		ft_rotaty_a(stack1, 1);
	return (0);
}
