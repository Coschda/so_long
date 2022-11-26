/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:16:45 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/26 04:54:17 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hexlen(unsigned long long int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

char	*ft_int_to_hex(unsigned long long int nb, int caps, int *error)
{
	int		i;
	char	*base;
	char	*rep;

	if (nb == 0)
		return (ft_strdup("0", error));
	if (caps == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = ft_hexlen(nb);
	rep = malloc(sizeof(char) * (ft_hexlen(nb) + 1));
	if (!rep)
	{
		*error = -1;
		return (NULL);
	}
	rep[i--] = '\0';
	while (nb > 0 && i >= 0)
	{
		rep[i] = base[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (rep);
}

int	ft_putadress(unsigned long long int nb, int *error)
{
	int		len;
	int		mal;
	char	*rep;

	if (nb == 0)
	{
		rep = "0";
		mal = 0;
	}
	else
	{
		rep = ft_int_to_hex(nb, 0, error);
		mal = 1;
	}
	ft_putchar("0x", 2, error);
	len = ft_intstr(rep, mal, error);
	return (len + 2);
}

int	ft_format(char c, void *arg, int *error)
{
	int	cmp;

	cmp = 0;
	if (c == 'c')
		cmp += ft_putchar(&arg, 1, error);
	if (c == 's')
		cmp += ft_intstr((char *)arg, 0, error);
	if (c == 'p')
		cmp += ft_putadress((unsigned long long int)arg, error);
	if (c == 'd' || c == 'i')
		cmp += ft_intnbr((int)arg, error);
	if (c == 'u')
		cmp += ft_uintnbr((unsigned int)arg, error);
	if (c == 'x')
		cmp += ft_intstr(ft_int_to_hex((unsigned int)arg, 0, error), 1, error);
	if (c == 'X')
		cmp += ft_intstr(ft_int_to_hex((unsigned int)arg, 1, error), 1, error);
	return (cmp);
}

int	ft_printf(const char *text, ...)
{
	t_index	cmp;
	va_list	args;

	cmp.i = -1;
	cmp.count = 0;
	cmp.error = 0;
	va_start(args, text);
	while (text[++cmp.i])
	{
		if (text[cmp.i] != '%')
			cmp.count += ft_putchar(&text[cmp.i], 1, &cmp.error);
		else
		{
			if (text[cmp.i + 1] == '%')
				cmp.count += ft_putchar(&text[cmp.i++], 1, &cmp.error);
			else
				cmp.count += ft_format(text[cmp.i++ + 1], va_arg(args, void *),
						&cmp.error);
		}
		if (cmp.error == -1)
			return (-1);
	}
	va_end(args);
	return (cmp.count);
}
/*
int	main()
{
	char str[] = "some string with %s hehe.";
	printf("%d\n", printf("%s\n", str));
	printf("%d\n", ft_printf("%s\n", str));
}*/
