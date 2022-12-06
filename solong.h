/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:54:30 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/06 09:40:35 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define SIZE 64
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_oui
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*n0;
	mlx_image_t		*st;
	int				noutc;
	int				nb_consum;
	char			**map;
	char			*path;
	int				*whpp;
	int				p_x;
	int				p_y;
	int				count;
	int				k_count;
}	t_oui;

typedef struct s_stuff
{
	uint32_t	xy[2];
	uint32_t	wh[2];
	int			t3;
	int			t4;
	int			fd;
	int			x;
	int			y;
	int			*wd;
	char		*buf;
	int			h;
}	t_stuff;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

//main.c

void		quit_program(t_oui *oui);
void		key_hook(mlx_key_data_t keydata, void *param);
int			check_args(int argc);
void		init_oui(t_oui *oui, char *argv[]);
int32_t		main(int argc, char *argv[]);

//render.c

void		render_sprite(t_oui *oui, int x, int y, char *path);
void		finn_anim_init(t_oui *oui);
void		render_map(t_oui *oui);
void		finn_animation(void *param);

//utils.c

int			into(char c, char *str);
void		*s_malloc(size_t size, t_oui *oui);
int			s_open(char *path);
int			ft_intlen(int n);
void		free_map(char ***map);

//utils2.c

char		*ft_itoa(int n);
char		*ft_strjoinn(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_bigstrlen(char **map);
void		quit_program2(t_oui *oui);

//gameutils.c

char		**copy_map(char *path);
int			display_error(int a, int b, int c);
void		player_find(char *buf, int *wd, int h);
int			*get_whpp(char *path);

//check_maps.c

int			check_square(char **map);
int			check_walls(char **map);
int			check_only(char **map);
int			check_minmax(char **map);
int			check_map(char *path);

//check_maps2.c

int			check_ber(char *path);

//check_possible.c

int			*fill(char **tab, t_point size, t_point cur, char wall);
int			nb_consum(char **map);
t_point		player_pos(char **map);
int			check_possible(char **map, char *path);

//can_move.c

int			count_k(t_oui *oui);
int			c_y(char c, int nb, t_oui *oui);
int			c_m(char c, int nb, t_oui *oui);

//ft_printf

char		*ft_strdup(const char *str, int *error);
int			ft_intstr(char *s, int mal, int *error);
int			ft_intnbr(int n, int *error);
int			ft_uintnbr(unsigned int n, int *error);
int			ft_putchar(const void *str, int len, int *error);
int			ft_hexlen(unsigned long long int nb);
int			ft_printf(const char *text, ...);

//get_next_line.c

int			in(char c, char *str);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *line, char *buff);
char		*get_next_line(int fd);

#endif
