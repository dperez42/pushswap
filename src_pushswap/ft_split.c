/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:04:49 by dperez-z          #+#    #+#             */
/*   Updated: 2019/11/19 14:22:58 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

static int	nword(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			n++;
		}
	}
	return (n);
}

static char	**ft_memalloc(int nword, char const *s, char c, int k)
{
	int		i;
	char	**dst;
	int		cont;

	i = 0;
	dst = ((char **)malloc(((nword) * sizeof(char *))));
	if (!dst)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			cont = 0;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				cont++;
			}
			dst[k++] = (char *)malloc((cont + 1) * sizeof(char));
		}
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dst;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	dst = ft_memalloc((nword(s, c) + 1), s, c, 0);
	while (s[i] != '\0' && k < (nword(s, c)))
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			j = 0;
			while (s[i] != c && s[i] != '\0')
				dst[k][j++] = s[i++];
			dst[k++][j] = '\0';
		}
	}
	dst[k] = 0;
	return (dst);
}
