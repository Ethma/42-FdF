/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:27:13 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/25 16:17:41 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freeproj(t_proj **proj, t_stock *stock)
{
	int x;

	x = 0;
	while (x < stock->linenum)
	{
		free(proj[x]);
		proj[x] = NULL;
		x++;
	}
	free(proj);
}

int		ft_exit(char *str, int i)
{
	if (i == 1)
	{
		ft_putendl(str);
		exit(-1);
	}
	return (0);
}

int		ft_exit_finish(char *str, int i, t_stock *stock)
{
	if (i == 2)
	{
		ft_putendl(str);
		exit(1);
	}
	return (0);
}
