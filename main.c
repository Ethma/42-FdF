/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:23:07 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/08 14:17:49 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_lines(int fd)
{
	char *line;
	int	i;
	
	i = 0;
	printf("into ft_count_lines\n");
	while (get_next_line(fd, &line))
		i++;
	close (fd);
	return (i);
}

int	fdf_start(int fd, const char *str)
{
 	char	*line;
	char	*buff;
	t_stock	stock;
	int		i;
	int		j;

	j = ft_count_lines(fd);
	i = 0;
	if ((stock.points = (t_points **)malloc(sizeof(t_points *) * j)) == NULL)
		return (0); 
	printf("after malloc\n");
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	while (i < j)
	{
		if ((stock.points.tab = (char **)malloc(sizeof(char *) * 1)) == NULL)
			return (0);
		while (get_next_line(fd, &line) > 0)
		{
			printf("after gnl\n");
			tab[i] = line;
			i++;
		}
	}
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