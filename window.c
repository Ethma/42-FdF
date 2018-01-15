/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:00:56 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/15 15:22:30 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_pixel_put_to_image(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		i;

	if (x >= WIN_W || y >= WIN_H)
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

void	draw_lines(int x1, int y1, int x2, int y2, t_stock *stock)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(stock->mlx, stock->window, x, y1+((y2 - y1) * (x - x1)) / (x2 - x1), 0xFFFFFF);
		x++;
	}
}