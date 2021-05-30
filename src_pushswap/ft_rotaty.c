#include "pushswap.h"

void	ft_rotaty_a(t_list **lst, int debug)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!*lst)
		return ;
	last = *lst;
	if (!last->next)
		return ;
	second = last->next;
	first = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*lst = second;
	if (debug)
		write(1, "ra\n", 3);
	return ;
}

void	ft_rotaty_a_2(t_list **lst)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!*lst || ft_lstsize(*lst) < 2)
		return ;
	last = *lst;
	if (!last->next)
		return ;
	second = last->next;
	first = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*lst = second;
	return ;
}

void	ft_rotaty_a_nb(t_list **lst, int nb, int debug)
{
	int	i;

	if (nb == 0)
		return ;
	i = 0;
	while (i < nb)
	{
		ft_rotaty_a(lst, debug);
		i++;
	}
	return ;
}

void	ft_rotaty_b(t_list **lst, int debug)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!*lst)
		return ;
	last = *lst;
	if (!last->next)
		return ;
	second = last->next;
	first = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*lst = second;
	if (debug)
		write(1, "rb\n", 3);
	return ;
}
