/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:54:08 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/04 01:32:12 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	move_ennemies(t_oui *oui)
{
	//Get whpp to parse the oui->map
	//Find every K and have an int that switches from 1 to 0
	//Check either right or left depending on the bool and if it's a 0, move it
}

int	c_y(char c, int nb, t_oui *oui)
{
	if (c == 'y')
	{
		if (oui->map[oui->p_y + nb][oui->p_x] == '1')
			return (0);
		if (oui->map[oui->p_y + nb][oui->p_x] == 'K')
			quit_program2(oui);
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
	if (c == 'x')
	{
		if (oui->map[oui->p_y][oui->p_x + nb] == '1')
			return (0);
		if (oui->map[oui->p_y][oui->p_x + nb] == 'K')
			quit_program2(oui);
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
