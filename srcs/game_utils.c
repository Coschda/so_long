/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 04:03:46 by mdoumi            #+#    #+#             */
/*   Updated: 2022/12/06 12:24:41 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	**copy_map(char *path)
{
	char	**rep;
	char	*buf;
	int		fd;
	int		j;

	j = 0;
	fd = s_open(path);
	buf = get_next_line(fd);
	rep = malloc(sizeof(char *) * get_whpp(path)[1] + 1);
	if (!rep)
		return (NULL);
	while (buf != NULL)
	{
		rep[j++] = ft_substr(buf, 0, ft_strlen(buf) - 1);
		buf = get_next_line(fd);
	}
	rep[j] = NULL;
	return (rep);
}

int	display_error(int a, int b, int c)
{
	if (a > 1)
	{
		ft_printf("Error\nToo much exits.\n");
		return (0);
	}
	if (a < 1)
	{
		ft_printf("Error\nToo few exits.\n");
		return (0);
	}
	if (b <= 0)
	{
		ft_printf("Error\nToo few consumables.\n");
		return (0);
	}
	if (c != 1)
	{
		ft_printf("Error\nMore or less than one spawn point.\n");
		return (0);
	}
	return (1);
}

void	player_find(char *buf, int *wd, int h)
{
	if (in('P', buf) != 0)
	{
		wd[2] = in('P', buf);
		wd[3] = h;
	}
}

void	mini_init(int *h, int *fd, char *path, char **buf)
{
	char	c;
	int		fakefd;

	fakefd = s_open(path);
	if (!read(fakefd, &c, 1))
	{
		ft_printf("Error\nEmpty Map.\n");
		close(fakefd);
		exit(0);
	}
	close(fakefd);
	*h = 0;
	*fd = s_open(path);
	*buf = get_next_line(*fd);
}

int	*get_whpp(char *path)
{
	t_stuff	a;

	a.wd = malloc(sizeof(int) * 4);
	if (!a.wd)
		return (NULL);
	mini_init(&a.h, &a.fd, path, &a.buf);
	if (into('P', a.buf) != -1)
	{
		a.wd[2] = into('P', a.buf);
		a.wd[3] = a.h;
	}
	a.wd[0] = ft_strlen(a.buf) - 1;
	while (a.buf != NULL && a.buf[0] != '\n')
	{
		if (into('P', a.buf) != -1)
		{
			a.wd[2] = into('P', a.buf);
			a.wd[3] = a.h;
		}
		a.buf = get_next_line(a.fd);
		a.h++;
	}
	free(a.buf);
	a.wd[1] = a.h;
	return (a.wd);
}
