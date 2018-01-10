/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:23:07 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/10 16:04:00 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_lines(int fd)
{
	char *line;
	int	i;
	
	i = 0;
	while (get_next_line(fd, &line))
		i++;
	close (fd);
	return (i);
}

int	fdf_start(int fd, const char *str)
{
 	char	*line;
	t_stock	*stock;
	int		i;
	int		j;
	
	stock = (t_stock *)malloc(sizeof(t_stock));
	j = ft_count_lines(fd);
	stock->tabint = (int **)malloc(sizeof(int *) * j);
	j = 0;
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line))
	{
		stock->tabint[j] = (int *)malloc(sizeof(int) * ft_strlen(line));
		i = 0;
		stock->tab = ft_strsplit(line, ' ');
		stock->index = ft_strrlen(stock->tab);
		while (stock->index--)
		{
			stock->tabint[j][i] = ft_atoi(stock->tab[i]);
			i++;
		}
	}
	ft_freetab2d(stock->tab);
	return (1);
}
int		main(int ac, char **av)
{
	int fd;

	if (ac < 2)
		ft_putendl("usage : ./fdf input_file");
	if (ac > 2)
		ft_putendl("ERROR : only one file needed");
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (fd > 0)
	{	
		if (!fdf_start(fd, av[1]))
			ft_putendl("ERROR : File is incorrect or does not exist");
	}
	return(0);
}