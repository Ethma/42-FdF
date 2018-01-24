/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:43:39 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/24 16:27:08 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		rread(int const fd, char **str)
{
	int		i;
	char	*s;
	char	buf[BUFF_SIZE + 1];

	if ((i = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[i] = '\0';
	s = *str;
	*str = ft_strjoin(*str, buf);
	if (*s != 0)
		free(s);
	return (i);
}

static int		gline(char **str, char **line, char *s)
{
	int		i;
	char	*buff;

	i = 0;
	if (*s == '\n')
		i = 1;
	*s = 0;
	*line = ft_strjoin("", *str);
	if (i == 0 && ft_strlen(*str) != 0)
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (i == 0 && !(ft_strlen(*str)))
		return (0);
	buff = *str;
	*str = ft_strjoin(s + 1, "");
	free(buff);
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	int			i;
	char		*s;
	static char	*str;

	if (str == 0)
		str = "";
	if (!line || BUFF_SIZE < 1)
		return (-1);
	i = BUFF_SIZE;
	while (line)
	{
		s = str;
		while (*s || i < BUFF_SIZE)
		{
			if (*s == '\n' || *s == 0)
				return (gline(&str, line, s));
			s++;
		}
		i = rread(fd, &str);
		if (i == -1)
			return (-1);
	}
	return (0);
}
