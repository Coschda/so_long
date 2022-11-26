/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:56:59 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/26 05:16:58 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	into(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	*s_malloc(size_t size, t_oui *oui)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
	{
		ft_printf("Error,  error.\n");
		quit_program(oui);
	}
	return (tmp);
}

int	s_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, Couldn't open the map.\n");
		return (-1);
	}
	return (fd);
}

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

//int	main()
//{
	//int	*a = get_whpp("./test.ber");
	//printf("%d %d %d %d\n", a[0], a[1],a[2], a[3]);
//}
