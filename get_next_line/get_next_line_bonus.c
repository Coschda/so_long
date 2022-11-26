/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:40:08 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/13 10:18:31 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*inperfect_line(int fd, char *rep)
{
	int		len;
	char	buf[BUFFER_SIZE + 1];

	len = 1;
	while (!in('\n', rep) && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(rep);
			return (NULL);
		}
		buf[len] = '\0';
		rep = ft_strjoin(rep, buf);
	}
	return (rep);
}

char	*perfect_new_line(char *str)
{
	int		i;
	char	*rep;

	if (!str[0])
		return (NULL);
	rep = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!rep)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rep[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		rep[i] = str[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}

char	*get_rab(char *str)
{
	t_index	all;

	all.i = 0;
	all.j = 0;
	while (str[all.i] && str[all.i] != '\n')
		all.i++;
	if (!str[all.i])
	{
		free(str);
		return (NULL);
	}
	all.tmp = malloc(sizeof(char) * ft_strlen(str) - all.i + 1);
	if (!all.tmp)
		return (NULL);
	all.i++;
	if (!all.tmp)
		return (NULL);
	while (str[all.i])
		all.tmp[all.j++] = str[all.i++];
	all.tmp[all.j] = '\0';
	free(str);
	return (all.tmp);
}

char	*get_next_line(int fd)
{
	static char	*rep[4096];
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rep[fd] = inperfect_line(fd, rep[fd]);
	if (!rep[fd])
		return (NULL);
	tmp = perfect_new_line(rep[fd]);
	rep[fd] = get_rab(rep[fd]);
	return (tmp);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int	main()
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error");
		return (1);
	}
	printf("%s", get_next_line(fd));
}*/
