/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:51:29 by dperez-z          #+#    #+#             */
/*   Updated: 2021/05/20 08:52:59 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(str) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *str, char *c)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(str) + ft_strlen(c) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = c[0];
	dest[i + 1] = '\0';
	free(str);
	return (dest);
}

char	*get_next_line(void)
{
	char	*buf;
	int		ret;
	char	*line;

	buf = malloc(1);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	ret = read(0, buf, 1);
	while (ret > 0)
	{
		if (buf[0] == '\n' || buf[0] == EOF)
			break ;
		line = ft_strchr(line, buf);
		ret = read(0, buf, 1);
	}
	free (buf);
	buf = NULL;
	return (line);
}
