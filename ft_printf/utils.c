/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:41:52 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/08 12:21:26 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static	int	ft_lenint(long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void	int_in_str(char *str, long int nb)
{
	int	i;
	int	len;

	len = ft_lenint(nb) -1;
	i = 0;
	while (len >= 0)
	{
		str[len] = '0' + nb % 10;
		nb = nb / 10;
		len--;
	}
}

int	ft_intstr(char *s, int mal, int *error)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putchar("(null)", 6, error);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(&s[i], 1, error);
		i++;
	}
	if (mal == 1)
		free(s);
	return (i);
}

int	ft_intnbr(int n, int *error)
{
	char	txt[11];
	t_index	count;

	count.j = 0;
	if (n == 0)
	{
		ft_putchar("0", 1, error);
		return (1);
	}
	count.i = 0;
	if (n < 0)
	{
		ft_putchar("-", 1, error);
		n = -n;
		count.j++;
	}
	if (n == -2147483648)
	{
		ft_putchar("2147483648", 10, error);
		return (11);
	}
	int_in_str(txt, n);
	while (count.i < ft_lenint(n))
		ft_putchar(&txt[count.i++], 1, error);
	return (count.j + count.i);
}

int	ft_uintnbr(unsigned int n, int *error)
{
	char	txt[11];
	t_index	count;

	count.j = 0;
	if (n == 0)
	{
		ft_putchar("0", 1, error);
		return (1);
	}
	count.i = 0;
	int_in_str(txt, n);
	while (count.i < ft_lenint(n))
		ft_putchar(&txt[count.i++], 1, error);
	return (count.j + count.i);
}
