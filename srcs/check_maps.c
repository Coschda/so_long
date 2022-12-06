/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:22:02 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/06 11:57:35 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	check_square(char **map)
{
	int		i;
	size_t	x;

	i = 0;
	x = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != x)
		{
			ft_printf("Error\nMap is not a rectangle.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int		i;
	int		j;
	int		tmp;

	j = -1;
	while (map[0][++j])
		if (map[0][j] != '1')
			return (0);
	i = 0;
	while (map[++i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
	}
	j = -1;
	tmp = ft_bigstrlen(map);
	while (map[tmp - 1][++j])
		if (map[tmp - 1][j] != '1')
			return (0);
	return (1);
}

int	check_only(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = -1;
		while (map[i][++j])
		{
			if (!in(map[i][j], "01ECPK\n"))
			{
				ft_printf("Error\nUnknown character in map.\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_minmax(char **map)
{
	int		i;
	int		j;
	int		cmp[3];

	i = 0;
	cmp[0] = 0;
	cmp[1] = 0;
	cmp[2] = 0;
	while (map[i] != NULL)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				cmp[0]++;
			if (map[i][j] == 'C')
				cmp[1]++;
			if (map[i][j] == 'P')
				cmp[2]++;
		}
		i++;
	}
	return (display_error(cmp[0], cmp[1], cmp[2]));
}

int	check_map(char *path)
{
	char	**map;

	if (!check_ber(path))
		return (0);
	map = copy_map(path);
	if (!check_square(map))
		return (0);
	if (!check_walls(map))
	{
		ft_printf("Error\nMap is not closed with walls.\n");
		return (0);
	}
	if (!check_only(map))
		return (0);
	if (!check_minmax(map))
		return (0);
	if (!check_possible(map, path))
		return (0);
	return (1);
}
