/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:09:09 by dperez-z          #+#    #+#             */
/*   Updated: 2021/06/11 15:10:26 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_array(char **str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return ;
	while (str[cnt])
	{
		free(str[cnt]);
		str[cnt++] = NULL;
	}
	free(str);
	str = NULL;
}
