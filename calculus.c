/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:02:08 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/15 15:20:52 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_proj		**ft_getheight(t_stock *stock)
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
			proj[y][x].z = proj[y][x].z * -1;
			x++;
		}
		y++;
	}
	return (proj);
}

static	int	check_lowest_point(t_proj **proj, t_stock *stock)
{
	int x;
	int y;
	int point;

	y = 0;
	point = proj[0][0].x;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index[y][0])
		{
			if (proj[y][x].x < point)
				point = proj[x][y].x;
			x++;
		}
		y++;
	}
	return (point < 0 ? -point : point);
}

static	int	check_lowest_line_point(t_proj **proj, t_stock *stock, int y)
{
	int x;
	int point;

	point = proj[0][0].x;
	while (x < stock->index[y][0])
	{
		if (proj[y][x].x < point)
			point = proj[x][y].x;
		x++;
	}
	return (point < 0 ? -point : point);
}

static	int	check_highest_line_point(t_proj **proj, t_stock *stock, int y)
{
	int x;
	int point;

	point = proj[0][0].x;
	while (x < stock->index[y][0])
	{
		if (proj[y][x].x > point)
			point = proj[x][y].x;
		x++;
	}
	return (point < 0 ? -point : point);
}


t_proj		**ft_projections(t_stock *stock, t_proj **proj)
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
			proj[y][x].z = proj[y][x].z * 500 / stock->linenum;
			proj[y][x].x = (0.5 * (x * 500 / stock->index[y][0])) - (0.75 * (y * (500 / 2) / stock->linenum));
			proj[y][x].y = proj[y][x].z + ((0.5 / 2) * (x * 500 / stock->index[y][0])) + ((0.75 / 2) * (y * 500 / stock->linenum));
			printf("x = %f ; y = %f ; z = %f\n", proj[y][x].x, proj[y][x].y, proj[y][x].z);
			x++;
		}
		y++;
	}
	return (proj);
}

int		draw_points(t_proj **proj, t_stock *stock)
{
	int	x;
	int y;
	int point;

	stock->mlx = mlx_init();
	stock->window = mlx_new_window(stock->mlx, WIN_W, WIN_H, "FDF");
	stock->image = mlx_new_image(stock->mlx, WIN_W, WIN_H);
	y = 0;
	point = check_lowest_point(proj, stock);
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index[y][0])
		{
			draw_lines(proj[y][x].x, proj[y][x].y, proj[y][x].x+1, proj[y][x].y+1, stock);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(stock->mlx, stock->window, stock->image, 0, 0);
	mlx_loop(stock->mlx);
	return (1);
}