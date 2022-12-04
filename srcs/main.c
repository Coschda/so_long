/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:04:47 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/04 01:24:59 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	quit_program(t_oui *oui)
{
	mlx_delete_image(oui->mlx, oui->n0);
	mlx_close_window(oui->mlx);
	free(oui->map);
	free(oui);
	exit(0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_oui	*oui;
	char	*temp;
	char	*tmp;

	oui = param;
	if (keydata.key == 68 && keydata.action == 1 && c_m('x', 1, oui))
		oui->p_x += 1;
	else if (keydata.key == 65 && keydata.action == 1 && c_m('x', -1, oui))
		oui->p_x -= 1;
	else if (keydata.key == 83 && keydata.action == 1 && c_m('y', 1, oui))
		oui->p_y += 1;
	else if (keydata.key == 87 && keydata.action == 1 && c_m('y', -1, oui))
		oui->p_y -= 1;
	else if (keydata.key == MLX_KEY_ESCAPE)
		quit_program(oui);
	else
		return ;
	oui->count++;
	mlx_delete_image(oui->mlx, oui->st);
	tmp = ft_itoa(oui->count);
	temp = ft_strjoinn("Mouvements : ", tmp);
	oui->st = mlx_put_string(oui->mlx, temp, 15, oui->whpp[1] * SIZE + 5);
	ft_printf("Mouvements : %d\n", oui->count);
	free(tmp);
	free(temp);
}

int	check_args(int argc)
{
	if (argc < 2)
	{
		ft_printf("Error\nNo map has been passed.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_printf("Error\nToo many arguments.\n");
		return (0);
	}
	return (1);
}

void	init_oui(t_oui *oui, char *argv[])
{
	oui->count = 0;
	oui->noutc = 0;
	oui->map = copy_map(argv[1]);
	oui->nb_consum = nb_consum(oui->map);
	oui->path = argv[1];
	oui->whpp = get_whpp(argv[1]);
	oui->p_x = oui->whpp[2];
	oui->p_y = oui->whpp[3];
	oui->mlx = mlx_init(oui->whpp[0] * SIZE,
			oui->whpp[1] * SIZE + 30, "so_long", true);
}

int32_t	main(int argc, char *argv[])
{
	t_oui	*oui;

	if (!check_args(argc) || !check_map(argv[1]))
		exit(-1);
	oui = malloc(sizeof(t_oui));
	if (!oui)
		return (1);
	init_oui(oui, argv);
	finn_anim_init(oui);
	render_map(oui);
	mlx_loop_hook(oui->mlx, &finn_animation, oui);
	mlx_key_hook(oui->mlx, &key_hook, oui);
	mlx_loop(oui->mlx);
	return (MLX_SUCCESS);
}
