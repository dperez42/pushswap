/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:47:38 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:47:40 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//load array of number in a lst
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

// check arguments
void	ft_check_all_args(int narg, char **argv, t_list **stacka)
{
	char	**str;
	int		i;

	if (narg == 1)
		ft_exit_ok();
	if (narg == 2)
	{
		if (ft_is_spc(argv[1]))
			ft_exit_ok();
		str = ft_split(argv[1], ' ');
		if (ft_check_arguments(str, 0) == 1 || ft_check_repeat(str, 0) == 1)
			ft_exit_error();
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

// return message
int	ft_check_msg(t_list *stacka, t_list *stackb)
{
	if (!ft_check(stacka) && stackb == NULL)
		ft_exit_ok();
	else
		return (1);
	return (0);
}

// Check if arguments are numbers
int	ft_check_arguments(char **argv, int begin)
{
	int	i;

	i = begin;
	while (argv[i])
	{
		if (ft_is_integer(argv[i]))
			return (1);
		i ++;
	}
	return (0);
}

// Check if arguments are repeated
int	ft_check_repeat(char **argv, int begin)
{
	int	i;
	int	j;

	i = begin;
	while (argv[i])
	{
		j = 1;
		while (argv[i + j])
		{
			if (ft_atoi_int(argv[i]) == ft_atoi_int(argv[i + j]))
				return (1);
			j++;
		}
		i ++;
	}
	return (0);
}
