/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 04:05:51 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/26 04:37:15 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_itoa(int n)
{
	int		i;
	int		boul;
	char	*rep;

	i = ft_intlen(n);
	boul = 0;
	rep = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (rep == NULL)
		return (NULL);
	if (n < 0)
	{
		boul = 1;
		n = -n;
	}
	rep[i] = '\0';
	while (i > 0)
	{
		rep[--i] = '0' + n % 10;
		n = n / 10;
	}
	if (boul == 1)
		rep[0] = '-';
	return (rep);
}

char	*ft_strjoinn(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*rep;

	if (!s1 || !s2)
		return (NULL);
	rep = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (rep == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		rep[i++] = s1[j++];
	j = 0;
	while (s2[j])
	{
		rep[i] = s2[j];
		i++;
		j++;
	}
	rep[i] = '\0';
	return (rep);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rep;

	if (start < ft_strlen(s))
		len = len + start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start < len)
		rep = malloc(sizeof(char) * (len - start + 1));
	else
		rep = malloc(sizeof(char));
	if (rep == NULL)
		return (NULL);
	i = start;
	while (i < len && s[i] != '\0')
	{
		rep[i - start] = s[i];
		i++;
	}
	rep[i - start] = '\0';
	return (rep);
}

int	ft_bigstrlen(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
