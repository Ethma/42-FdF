/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:23:07 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/03 16:58:49 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_start(int fd, const char *str)
{
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{

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