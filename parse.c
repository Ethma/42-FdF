/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:05:11 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/02 15:41:49 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	entry_check(int fd)
{
	t_stock	stock;
	char	*str;
	int		i;
	char	**tab;

	i = 0;
	tab =(char **)malloc(sizeof(tab) * 100);
	while (get_next_line(fd, &str))
	{
		ft_strsplit(str, ' ');
		stock.points[x][y] = tab[x];
		ft_putstr(tab[i]);
		i++;
	}
}