/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:31:39 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/25 16:26:39 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_lowest_xpoint(t_proj **proj, t_stock *stock)
{
	int x;
	int y;
	int point;

	y = 0;
	point = proj[0][0].x;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index)
		{
			if (proj[y][x].x < point)
				point = proj[y][x].x;
			x++;
		}
		y++;
	}
	return (point);
}

int	check_lowest_ypoint(t_proj **proj, t_stock *stock)
{
	int x;
	int y;
	int point;

	y = 0;
	point = proj[0][0].y;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index)
		{
			if (proj[y][x].y < point)
				point = proj[y][x].y;
			x++;
		}
		y++;
	}
	return (point);
}

int	check_highest_xpoint(t_proj **proj, t_stock *stock)
{
	int x;
	int y;
	int point;

	y = 0;
	point = proj[0][0].x;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index)
		{
			if (proj[y][x].x > point)
				point = proj[y][x].x;
			x++;
		}
		y++;
	}
	return (point < 0 ? -point : point);
}

int	check_highest_ypoint(t_proj **proj, t_stock *stock)
{
	int x;
	int y;
	int point;

	y = 0;
	point = proj[0][0].y;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index)
		{
			if (proj[y][x].y > point)
				point = proj[y][x].y;
			x++;
		}
		y++;
	}
	return (point < 0 ? -point : point);
}
