/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:23:07 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/24 14:25:29 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		empty_file(int fd)
{
	int ret;
	char *buff[1];

	if ((ret = read(fd, buff, 1)) <= 0)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int fd;

	if (ac < 2)
	{
		ft_putendl("usage : ./fdf input_file");
		return (0);
	}
	if (ac > 2)
	{
		ft_putendl("ERROR : only one file needed");
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (empty_file(fd) == 0)
	{
		ft_putendl("ERROR : File is incorrect or does not exist");
		return (0);
	}
	close(fd);
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (fdf_start(fd, av[1]) == 1)
		ft_putendl("ERROR : File is incorrect or does not exist");
	return (0);
}