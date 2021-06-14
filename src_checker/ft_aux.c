/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:41:32 by dperez-z          #+#    #+#             */
/*   Updated: 2021/04/13 10:46:21 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi_int(const char *str)
{
	int						sign;
	unsigned long long int	result;

	sign = 1;
	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (*str == '\0')
		ft_exit_error();
	while (!ft_isdigit(*str) && *str)
	{
		result = result * 10 + *str - '0';
		str++;
		if ((result > 2147483647) && sign >= 0)
			ft_exit_error();
		if ((result > 2147483648) && sign < 0)
			ft_exit_error();
	}
	return (sign * result);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (0);
	return (1);
}

int	ft_is_integer(char *str)
{
	int	i;
	int	flsig;
	int	flnb;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *char1, char *char2)
{
	int	i;

	i = 0;
	if (ft_strlen(char1) != ft_strlen(char2))
		return (-1);
	while (char1[i])
	{
		if (char1[i] != char2[i])
			return (char1[i] - char2[i]);
		i++;
	}
	return (0);
}

//check is only spaces
int	ft_is_spc(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i ++;
	}
	return (1);
}
