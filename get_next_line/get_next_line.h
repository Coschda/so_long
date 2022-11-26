/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoumi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:14:04 by mdoumi            #+#    #+#             */
/*   Updated: 2022/11/13 11:25:39 by mdoumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_index
{
	int		i;
	int		j;
	char	*tmp;
}	t_index;

int		in(char c, char *str);
size_t	ft_strlen(const char *str);

char	*ft_strjoin(char *line, char *buff);
char	*get_next_line(int fd);

#endif
