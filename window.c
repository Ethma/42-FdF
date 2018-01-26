/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:00:56 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/26 17:08:52 by mabessir         ###   ########.fr       */
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

void			draw_lines(int x1, int x2, int y2, t_stock *stock)
{
	if (abs(x2 - x1) >= abs(y2 - (int)stock->projy))
	{
		if (x2 >= x1)
			draw_lines_x(x1, x2, y2, stock);
		else
			draw_lines_x2(x2, y2, x1, stock);
	}
	else
	{
		if (y2 >= stock->projy)
			draw_lines_y(x1, x2, y2, stock);
		else
			draw_lines_y2(x2, y2, x1, stock);
	}
}
