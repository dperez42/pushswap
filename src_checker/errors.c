/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:47:54 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/20 10:04:21 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	ft_check_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_integer(argv[i]))
			return (1);
		i ++;
	}
	return (0);
}

int	ft_check_repeat(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[i + j])
		{
			if (ft_atoi_int(argv[i]) == ft_atoi_int(argv[i + j]))
				return (1);
			j++ ;
		}
		i ++;
	}
	return (0);
}

void	ft_exit_ok(void)
{
	write(1, "OK\n", 3);
	exit (0);
}
