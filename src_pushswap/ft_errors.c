/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:47:54 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/27 12:34:32 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_exit_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	ft_exit_error2(void)
{
	write (2, "Error\n", 6);
	exit (1);
	return (0);
}

void	ft_exit_ok(void)
{
	exit(0);
	return ;
}