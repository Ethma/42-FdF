/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:02:08 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/12 16:35:31 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_proj	**ft_getheight(t_stock *stock)
{
	t_proj	**proj;
	int		x;
	int		y;

	proj = (t_proj **)malloc(sizeof(t_proj *) * stock->linenum);
	y = 0;
	while (y < stock->linenum)
	{
		proj[y] =(t_proj *)malloc(sizeof(t_proj) * stock->index[y][0]);
		x = 0;
		while (x < stock->index[y][0]) 
		{
			proj[y][x].z = stock->tabint[y][x];
			x++;
		}
		y++;
	}
	return (proj);
}

void	ft_projections(t_stock *stock, t_proj **proj)
{
	int		x;
	int		y;
	int		k;

	y = 0;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index[y][0])
		{
			proj[y][x].x = ((sqrt(2)/2) * (x - y));
			proj[y][x].y = ((sqrt(2/3) * proj[y][x].z) - ((1/sqrt(6)) * (x + y)));
			x++;
		}
		y++;
	}
}