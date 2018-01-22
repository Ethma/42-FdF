/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:05:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/22 16:17:35 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_count_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
		i++;
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
		if (!(stock->index[j] = (int *)malloc(sizeof(int))))
			ft_exit("Malloc ERROR", 1);
		i = 0;
		stock->tab = ft_strsplit(line, ' ');
		free(line);
		stock->index[j][0] = ft_strrlen(stock->tab);
		while (i < stock->index[j][0])
		{
			stock->tabint[j][i] = ft_atoi(stock->tab[i]);
			i++;
		}
		j++;
	}
}

static	void ft_test(t_stock *stock)
{
	int j;

	j = 0;
	while (j < stock->linenum)
	{
		ft_putnbr(stock->index[j][0]);
		ft_putchar('\n');
		j++;
	}
}

int			fdf_start(int fd, const char *str)
{
	char	*line;
	t_stock	*stock;
	int		i;
	int		j;
	t_proj	**proj;

	if (!(stock = (t_stock *)malloc(sizeof(t_stock))))
		ft_exit("Malloc ERROR", 1);
	j = ft_count_lines(fd);
	if (!(stock->tabint = (int **)malloc(sizeof(int *) * j)))
		ft_exit("Malloc ERROR", 1);
	if (!(stock->index = (int **)malloc(sizeof(int *) * j)))
		ft_exit("Malloc ERROR", 1);
	stock->linenum = j;
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	ft_get_tabint(fd, stock, line);
	ft_freetab2d(stock->tab);
	proj = ft_projections(stock, ft_getheight(stock));
//	ft_test(stock);
	draw_points(proj, stock);
	return (1);
}