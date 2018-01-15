/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:21 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/15 15:26:38 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	draw_lines(void *mlx, void *window, int x1, int y1, int x2, int y2)
{
	int x;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(mlx, window, x, y1+((y2 - y1) * (x - x1)) / (x2 - x1), 0xFFFFFF);
		x++;
	}
}

int		main()
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "Bonjour");
	draw_lines(mlx, window, 10, 10, 40, 40);
	mlx_loop(mlx);
	return (0);
}