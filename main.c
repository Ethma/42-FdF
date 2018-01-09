/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:23:07 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/09 13:02:40 by mabessir         ###   ########.fr       */
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
	char	**tab;
	int		**tabint;
	int		i;
	int		j;
	
	j = ft_count_lines(fd);
	tabint = (int **)malloc(sizeof(int *) * j);
	j = 0;
	while (get_next_line(fd, &line))
	{
		tabint[j] = (int *)malloc(sizeof(int ) * ft_strlen(line));
		i = 0;
		ft_putendl("test 1 passed");
		tab = ft_strsplit(line, ' ');
		ft_putendl("test 2 passed");
		while (i < ft_strlen(line))
		{
			ft_putendl("test 3 passed");
			tabint[j][i] = ft_atoi(tab[i]);
			ft_putendl("test 3.2 passed");
			i++;
		}
		ft_putendl("test 4 passed");
	}
	ft_putendl("test 5 passed");
	ft_freetab2d(tab);
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