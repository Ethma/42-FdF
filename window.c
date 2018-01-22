/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:00:56 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/22 15:42:11 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			mlx_pixel_put_to_image(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		i;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	i = x * (bpp / 8) + y * sizeline;
	data[i] = color % 256;
	color /= 256;
	data[i + 1] = color % 256;
	color /= 256;
	data[i + 2] = color % 256;
	color /= 256;
	data[i + 3] = 0;
	color /= 256;
}

static	void	draw_lines_x(int x1, int y1, int x2, int y2, t_stock *stock)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put_to_image(stock->image, x, y1+((y2 - y1) * (x - x1)) / (x2 - x1), stock->color);
		x++;
	}
}

static	void	draw_lines_y(int x1, int y1, int x2, int y2, t_stock *stock)
{
	int y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put_to_image(stock->image, x1+((x2 - x1) * (y - y1)) / (y2 - y1), y, stock->color);
		y++;
	}
}

void			draw_lines(int x1, int y1, int x2, int y2, t_stock *stock)
{
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		if (x2 >= x1)
			draw_lines_x(x1, y1, x2, y2, stock);
		else
			draw_lines_x(x2, y2, x1, y1, stock);
	}
	else
	{
		if (y2 >= y1)
			draw_lines_y(x2, y2, x1, y1, stock);
		else
				draw_lines_y(x2, y2, x1, y1, stock);
	}
}