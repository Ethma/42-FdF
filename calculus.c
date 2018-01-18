/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:02:08 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/18 16:04:58 by mabessir         ###   ########.fr       */
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
		while (x < stock->index[0][0]) 
		{
			proj[y][x].z = stock->tabint[y][x];
			proj[y][x].z = proj[y][x].z * -1;
			proj[y][x].x = x * ((WIN_W / 2) / stock->index[0][0]);
			proj[y][x].y = y * ((WIN_H / 2) / stock->linenum);
			proj[y][x].z = proj[y][x].z * ((WIN_W / 2) / stock->index[y][0]);
			x++;
		}
		y++;
	}
	ft_freetabint2d(stock->tabint, stock->linenum);
	return (proj);
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
		while (x < stock->index[0][0])
		{
			proj[y][x].x = (0.5 * proj[y][x].x) - (0.75 * proj[y][x].y);
			proj[y][x].y = proj[y][x].z + ((0.5 / 2) * proj[y][x].x) + ((0.75 / 2) * proj[y][x].y);
			x++;
		}
		y++;
	}
	return (proj);
}

static	void	ft_scaling(t_proj ***proj, t_stock *stock)
{
	int x;

	x = 0;
}

int		draw_points(t_proj **proj, t_stock *stock)
{
	int	x;
	int y;
	int xpoint;
	int ypoint;

	stock->mlx = mlx_init();
	stock->window = mlx_new_window(stock->mlx, WIN_W, WIN_H, "FDF");
	stock->image = mlx_new_image(stock->mlx, WIN_W, WIN_H);
	y = 0;
	ft_putendl("yolo");
//	ft_scaling(&proj, stock);
	xpoint = check_lowest_xpoint(proj, stock) - 500;
	ypoint = check_lowest_ypoint(proj, stock) - 200;
	if (ypoint > 0)
		ypoint = 0;
	if (xpoint > 0)
		xpoint = 0;
	ft_putendl("yolo");
	while (y < stock->linenum - 1)
	{
		x = 0;
		while (x < stock->index[0][0] - 1)
		{
			draw_lines(proj[y][x].x-xpoint, proj[y][x].y-ypoint, proj[y][x+1].x-xpoint, proj[y][x+1].y-ypoint, stock);
			draw_lines(proj[y][x].x-xpoint, proj[y][x].y-ypoint, proj[y+1][x].x-xpoint, proj[y+1][x].y-ypoint, stock);
			x++;
		}
		y++;
	}
	ft_putendl("ultrayolo");
	mlx_put_image_to_window(stock->mlx, stock->window, stock->image, 0, 0);
	mlx_loop(stock->mlx);
	return (1);
}