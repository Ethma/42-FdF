/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:24:14 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/29 10:06:05 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines_x(int x1, int x2, int y2, t_stock *stock)
{
	int x;
	int y1;

	y1 = stock->projy;
	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put_to_image(stock->image, x, y1 + ((y2 - y1) *
		(x - x1)) / (x2 - x1), stock->color);
		x++;
	}
}

void	draw_lines_y(int x1, int x2, int y2, t_stock *stock)
{
	int y;
	int y1;

	y1 = stock->projy;
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put_to_image(stock->image, x1 + ((x2 - x1) * (y - y1)) /
		(y2 - y1), y, stock->color);
		y++;
	}
}

void	draw_lines_x2(int x1, int y1, int x2, t_stock *stock)
{
	int x;
	int y2;

	y2 = stock->projy;
	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put_to_image(stock->image, x, y1 + ((y2 - y1) *
		(x - x1)) / (x2 - x1), stock->color);
		x++;
	}
}

void	draw_lines_y2(int x1, int y1, int x2, t_stock *stock)
{
	int y;
	int y2;

	y2 = stock->projy;
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put_to_image(stock->image, x1 + ((x2 - x1) *
		(y - y1)) / (y2 - y1), y, stock->color);
		y++;
	}
}
