/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:54:45 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/26 04:22:02 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	render_sprite(t_oui *oui, int x, int y, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(oui->mlx, texture);
	mlx_image_to_window(oui->mlx, img, x * SIZE, y * SIZE);
}

void	finn_anim_init(t_oui *oui)
{
	t_stuff	b;

	b.xy[0] = 0;
	b.xy[1] = 0;
	b.wh[0] = SIZE;
	b.wh[1] = SIZE;
	oui->texture = mlx_load_png("./assets/finn/FinnSprite.png");
	oui->n0 = mlx_texture_area_to_image(oui->mlx, oui->texture, b.xy, b.wh);
	b.t3 = oui->whpp[2] * SIZE;
	b.t4 = oui->whpp[3] * SIZE;
	mlx_image_to_window(oui->mlx, oui->n0, oui->whpp[0], oui->whpp[1]);
	oui->st = mlx_put_string(oui->mlx, "Mouvements : 0", 15,
			oui->whpp[1] * SIZE + 5);
}

void	render_map(t_oui *oui)
{
	int	i;
	int	j;

	i = -1;
	while (oui->map[++i] != NULL)
	{
		j = -1;
		while (oui->map[i][++j])
		{
			if (oui->map[i][j] == '1')
				render_sprite(oui, j, i, "assets/pixil-frame-0.png");
			if (oui->map[i][j] == '0')
				render_sprite(oui, j, i, "assets/flower(1)(1).png");
			if (oui->map[i][j] == 'C')
				render_sprite(oui, j, i, "assets/jaeuh.png");
			if (oui->map[i][j] == 'P')
				render_sprite(oui, j, i, "assets/spawn.png");
			if (oui->map[i][j] == 'E')
				render_sprite(oui, j, i, "assets/beemoo.png");
			if (oui->map[i][j] == 'K')
				render_sprite(oui, j, i, "assets/bee.png");
		}
	}
}

void	finn_animation(void *param)
{
	static int			count = 0;
	t_oui				*oui;
	static uint32_t		xy[2] = {0, 0};
	uint32_t			wh[2];

	wh[0] = SIZE;
	wh[1] = SIZE;
	oui = param;
	if (count++ > 10)
	{
		if (xy[0] < SIZE * 8)
			xy[0] += SIZE;
		else
			xy[0] = SIZE;
		count = 0;
	}
	mlx_delete_image(oui->mlx, oui->n0);
	oui->n0 = mlx_texture_area_to_image(oui->mlx, oui->texture, xy, wh);
	mlx_image_to_window(oui->mlx, oui->n0, oui->p_x * SIZE, oui->p_y * SIZE);
}
