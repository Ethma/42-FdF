/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:35:21 by mabessir          #+#    #+#             */
/*   Updated: 2017/12/13 15:47:04 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main()
{
	void	*mlx;
	void	*window;
	int		x;
	int		y;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "Bonjour");
	y = 0;
	while(y <= 600)
	{
		x = 0;
		while (x <= 800)
		{
			mlx_pixel_put(mlx, window, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx);
	return (0);
}