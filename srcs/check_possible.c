/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:13:01 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/28 18:37:07 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	*fill(char **tab, t_point size, t_point cur, char wall)
{
	static int	c[2] = {0, 0};

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == wall || tab[cur.y][cur.x] == 'K')
		return (NULL);
	if (tab[cur.y][cur.x] == 'C')
		c[0]++;
	if (tab[cur.y][cur.x] == 'E')
		c[1]++;
	tab[cur.y][cur.x] = wall;
	fill(tab, size, (t_point){cur.x - 1, cur.y}, wall);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, wall);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, wall);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, wall);
	return (c);
}

int	nb_consum(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (count);
}

t_point	player_pos(char **map)
{
	t_point	rep;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rep.x = 0;
	rep.y = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				rep.y = i;
				rep.x = j;
				return (rep);
			}
			j++;
		}
		i++;
	}
	return (rep);
}

int	check_possible(char **map, char *path)
{
	int	*check;
	int	nb;

	nb = nb_consum(map);
	check = fill(map, (t_point){get_whpp(path)[0], get_whpp(path)[1]},
			player_pos(map), '1');
	if (check[1] == 1 && check[0] == nb)
		return (1);
	ft_printf("Error, map is not doable.\n");
	return (0);
}
