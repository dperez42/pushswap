/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:52:34 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/20 09:16:19 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_load(int narg, char **argv, t_list **stacka, int begin)
{
	int		i;
	t_list	*tmp;

	i = narg - 1;
	while (i >= (0 + begin))
	{
		tmp = ft_lstnew(ft_atoi_int(argv[i]));
		ft_lstadd_front(stacka, tmp);
		i--;
	}
	return ;
}

void	ft_check_all_args(int narg, char **argv, t_list **stacka)
{
	char	**str;
	int		i;

	if (narg == 2)
	{
		if (ft_is_spc(argv[1]))
			exit (0);
		str = ft_split(argv[1], ' ');
		if (ft_check_arguments(str, 0) == 1 || ft_check_repeat(str, 0) == 1)
		{
			ft_free_array(str);
			ft_exit_error();
		}
		i = 0;
		while (str[i] != 0)
			i++;
		ft_load(i, str, stacka, 0);
		ft_free_array(str);
		return ;
	}
	if (ft_check_arguments(argv, 1) == 1 || ft_check_repeat(argv, 1) == 1)
		ft_exit_error();
	ft_load(narg, argv, stacka, 1);
	return ;
}

int	ft_check_msg(t_list *stacka, t_list *stackb)
{
	if (!ft_check(stacka) && stackb == NULL)
		ft_exit_ok();
	else
	{
		write(1, "KO\n", 3);
		return (1);
	}
	return (0);
}

int	main(int narg, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	char	*line;
	int		result;

	stacka = NULL;
	stackb = NULL;
	if (narg == 1)
		exit (0);
	ft_check_all_args(narg, argv, &stacka);
	while (1)
	{
		line = get_next_line();
		if (line[0] == 0)
		{
			free(line);
			break ;
		}
		result = ft_commands(line, &stacka, &stackb);
		if (result == 1)
			write(2, "Error\n", 6);
		free(line);
	}
	ft_check_msg(stacka, stackb);
	return (0);
}
