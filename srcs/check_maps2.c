/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:22:28 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/04 01:22:28 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len > 3 && ft_strcmp(ft_substr(path, len - 4, 4), ".ber") == 0)
		return (1);
	ft_printf("Error\nMap is not a .ber file.\n");
	return (0);
}

int	count_k(t_oui *oui)
{
	int	k_count;
	int	i;
	int	j;

	k_count = 0;
	i = 0;
	while (i < oui->whpp[1])
	{
		j = 0;
		while (j < oui->whpp[0])
		{
			if (oui->map[i][j] == 'K')
				k_count++;
			j++;
		}
		i++;
	}
	return (k_count);
}
