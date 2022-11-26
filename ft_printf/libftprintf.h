/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:36:24 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/26 03:46:51 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>
# include <string.h>

typedef struct s_index
{
	int	i;
	int	j;
	int	count;
	int	error;
}	t_index;
char	*ft_strdup(const char *str, int *error);

int		ft_intstr(char *s, int mal, int *error);
int		ft_intnbr(int n, int *error);
int		ft_uintnbr(unsigned int n, int *error);
int		ft_putchar(const void *str, int len, int *error);

int		ft_hexlen(unsigned long long int nb);
int		ft_printf(const char *text, ...);

#endif
