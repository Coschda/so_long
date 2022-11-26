/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:46:04 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/26 03:48:18 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../solong.h"

char	*ft_strdup(const char *str, int *error)
{
	int		i;
	char	*rep;

	i = 0;
	rep = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (rep == NULL)
	{
		*error = -1;
		return (NULL);
	}
	while (str[i])
	{
		rep[i] = str[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}

int	ft_putchar(const void *str, int len, int *error)
{
	int	nb;

	nb = 0;
	if (*error != -1)
		nb = write(1, str, len);
	if (nb == -1)
		*error = -1;
	return (nb);
}
