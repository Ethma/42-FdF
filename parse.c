/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:05:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/25 16:30:42 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_count_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (i);
}

static	void	ft_get_tabint(int fd, t_stock *stock, char *line)
{
	int i;
	int j;

	j = 0;
	while (get_next_line(fd, &line))
	{
		if (!(stock->tabint[j] = (int *)malloc(sizeof(int) * ft_strlen(line))))
			ft_exit("Malloc ERROR", 1);
		i = 0;
		stock->tab = ft_strsplit(line, ' ');
		stock->index = ft_strrlen(stock->tab);
		while (i < stock->index)
		{
			stock->tabint[j][i] = ft_atoi(stock->tab[i]);
			i++;
		}
		free(line);
		ft_freetab2d(stock->tab);
		j++;
	}
	close(fd);
}

int				fdf_start(int fd, const char *str)
{
	char	*line;
	t_stock	stock;
	int		i;
	int		j;
	t_proj	**proj;

	j = ft_count_lines(fd);
	if (!(stock.tabint = (int **)malloc(sizeof(int *) * j)))
		ft_exit("Malloc ERROR", 1);
	stock.linenum = j;
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	ft_get_tabint(fd, &stock, line);
	proj = ft_getheight(&stock);
	ft_projections(&stock, proj);
	draw_points(proj, &stock);
	return (1);
}
