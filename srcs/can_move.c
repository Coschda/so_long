/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:54:08 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/07 11:31:23 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	show_it(t_oui *oui, int y, int x, int c)
{
	char	tmp;

	tmp = oui->map[y][x];
	oui->map[y][x] = oui->map[y][c];
	oui->map[y][c] = tmp;
	render_sprite(oui, c, y, "assets/bee.png");
	render_sprite(oui, x, y, "assets/flower(1)(1).png");
}

void	move_it(t_oui *oui, int y, int x)
{
	static int	boul = 0;
	static int	count = 0;

	if (boul < oui->k_count)
	{
		if (oui->map[y][x + 1] == '0')
			show_it(oui, y, x, x + 1);
		boul++;
	}
	else if (boul >= oui->k_count)
	{
		if (oui->map[y][x - 1] == '0')
			show_it(oui, y, x, x - 1);
		count++;
		if (count >= oui->k_count)
		{
			count = 0;
			boul = 0;
		}
	}
}

void	move_ennemies(t_oui *oui)
{
	int	i;
	int	j;

	i = 0;
	while (i < oui->whpp[1])
	{
		j = 0;
		while (j < oui->whpp[0])
		{
			if (oui->map[i][j] == 'K')
				move_it(oui, i, j++);
			j++;
		}
		i++;
	}
}

int	c_y(char c, int nb, t_oui *oui)
{
	if (c == 'y')
	{
		if (oui->map[oui->p_y + nb][oui->p_x] == '1')
			return (0);
		if (oui->map[oui->p_y + nb][oui->p_x] == 'C')
		{
			oui->map[oui->p_y + nb][oui->p_x] = '0';
			oui->noutc++;
			render_map(oui);
			return (1);
		}
		if (oui->map[oui->p_y + nb][oui->p_x] == 'E')
			if (oui->noutc == oui->nb_consum)
				quit_program2(oui);
	}
	return (1);
}

int	c_m(char c, int nb, t_oui *oui)
{
	move_ennemies(oui);
	if (c == 'x')
	{
		if (oui->map[oui->p_y][oui->p_x + nb] == '1')
			return (0);
		if (oui->map[oui->p_y][oui->p_x + nb] == 'C')
		{
			oui->map[oui->p_y][oui->p_x + nb] = '0';
			oui->noutc++;
			render_map(oui);
			return (1);
		}
		if (oui->map[oui->p_y][oui->p_x + nb] == 'E')
			if (oui->noutc == oui->nb_consum)
				quit_program2(oui);
	}
	return (c_y(c, nb, oui));
}
