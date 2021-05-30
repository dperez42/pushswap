/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:29:21 by dperez-z          #+#    #+#             */
/*   Updated: 2021/04/13 10:40:41 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_command_swap(char *line, t_list **stackA, t_list **stackB)
{
	if (!ft_strcmp(line, "sa"))
	{
		ft_swapT(stackA);
		return (0);
	}
	if (!ft_strcmp(line, "sb"))
	{
		ft_swapT(stackB);
		return (0);
	}
	if (!ft_strcmp(line, "ss"))
	{
		ft_swapAll(stackA, stackB);
		return (0);
	}
	 return (1);
}

int	ft_command_push(char *line, t_list **stackA, t_list **stackB)
{
	if (!ft_strcmp(line, "pa"))
	{
		ft_pushT(stackB, stackA);
		return (0);
	}
	if (!ft_strcmp(line, "pb"))
	{
		ft_pushT(stackA, stackB);
		return (0);
	}
	return (1);
}

int	ft_command_rotaty(char *line, t_list **stackA, t_list **stackB)
{
	if (!ft_strcmp(line, "ra"))
	{
		ft_rotatyT(stackA);
		return (0);
	}
	if (!ft_strcmp(line, "rb"))
	{
		ft_rotatyT(stackB);
		return (0);
	}
	if (!ft_strcmp(line, "rr"))
	{
		ft_rotatyAll(stackA, stackB);
		return (0);
	}
	return (1);
}

int	ft_command_reverse(char *line, t_list **stackA, t_list **stackB)
{
	if (!ft_strcmp(line, "rra"))
	{
		ft_reversyT(stackA);
		return (0);
	}
	if (!ft_strcmp(line, "rrb"))
	{
		ft_reversyT(stackB);
		return (0);
	}
	if (!ft_strcmp(line, "rrr"))
	{
		ft_reversyAll(stackA, stackB);
		return (0);
	}
	return (1);
}

int	ft_commands(char *line, t_list **stackA, t_list **stackB)
{
	if (!ft_command_swap(line, stackA, stackB))
		return (0);
	if (!ft_command_push(line, stackA, stackB))
		return (0);
	if (!ft_command_rotaty(line, stackA, stackB))
		return (0);
	if (!ft_command_reverse(line, stackA, stackB))
		return (0);
	return (1);
}
