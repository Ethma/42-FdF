/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:30:09 by golliet           #+#    #+#             */
/*   Updated: 2018/01/24 17:18:11 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <limits.h>

#define X '\n'
#define TMP tmp[fd]

void	ft_test(char **tmp, int fd, char *str, char *line_return)
{
	str = TMP;
	TMP = ft_strdup(line_return);
	ft_putendl("avant");
	free(str);
	ft_putendl("apres");
}

int		get_next_line(const int fd, char **line)
{
	int				rd;
	static char		*tmp[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*str;
	char			*line_return;

	if (fd < 0 || line == NULL || fd >= OPEN_MAX || (*line = NULL))
		return (-1);
	while ((!TMP || !ft_strchr(TMP, X)) && (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		str = TMP;
		TMP = ft_strjoin(TMP, buf);
		ft_strdel(&str);
	}
	if (!TMP || !ft_strlen(TMP))
		return (rd == -1 ? -1 : 0);
	if ((line_return = ft_strchr(TMP, X) + 1))
	{
		ft_putendl("bjr");
		*line = ft_strsub(TMP, 0, line_return - TMP - 1);
		ft_test(tmp, fd, str, line_return);
	}
	else if (!line_return && (*line = ft_strdup(TMP)) != NULL)
		ft_strdel(&TMP);
	return (1);
}