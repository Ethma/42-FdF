/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:23:07 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/25 15:11:43 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_check(int fd, char *str)
{
	int		ret;
	char	*buff;
	int		i;

	i = 0;
	buff = (char*)malloc(sizeof(char) * 1000000);
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	if ((ret = read(fd, buff, BUFFF_SIZE)) <= 0)
	{
		free(buff);
		return (0);
	}
	while (buff[i])
	{
		if ((ft_isdigit(buff[i]) != 1) && buff[i] != '-' && buff[i] != '\n'
		&& buff[i] != ' ')
		{
			free(buff);
			return (0);
		}
		i++;
	}
	free(buff);
	return (1);
}

int				main(int ac, char **av)
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
	if (fdf_check(fd, av[1]) == 0)
	{
		ft_putendl("ERROR : File is incorrect or does not exist");
		return (0);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (fdf_start(fd, av[1]) == 1)
		ft_putendl("ERROR : File is incorrect or does not exist");
	return (0);
}
