/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:09:49 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/13 10:11:46 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	in(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	t_index	a;
	char	*res;

	a.i = 0;
	a.j = 0;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	if (!buff || !line)
		return (NULL);
	res = malloc((ft_strlen(line) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (line[a.j])
		res[a.i++] = line[a.j++];
	a.j = 0;
	while (buff[a.j])
		res[a.i++] = buff[a.j++];
	res[a.i] = '\0';
	free(line);
	return (res);
}
