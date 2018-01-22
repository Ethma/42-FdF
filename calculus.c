/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:02:08 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/22 16:28:06 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_proj		**ft_getheight(t_stock *stock)
{
	t_proj	**proj;
	int		x;
	int		y;

	if (!(proj = (t_proj **)malloc(sizeof(t_proj *) * stock->linenum)))
		ft_exit("Malloc ERROR", 1);
	y = 0;
	while (y < stock->linenum)
	{
		if (!(proj[y] =(t_proj *)malloc(sizeof(t_proj) * stock->index[y][0])))
			ft_exit("Malloc ERROR", 1);
		x = 0;
		while (x < stock->index[0][0]) 
		{
			proj[y][x].z = stock->tabint[y][x];
			proj[y][x].height = stock->tabint[y][x];
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

int ft_color(double z)
{
	if (z == 0)
		return (0x00682F73);
	if (z == 1)
		return (0x00D733B4);
	if (z == 2)
		return (0x00D733B4);
	if (z == 3)
		return (0x00D733B4);
	if (z == 4)
		return (0x0092C9EB);
	if (z >= 5)
		return (0x00A4D867);
	return (0);
}

static	void	ft_freeproj(t_proj **proj, t_stock *stock)
{
	int x;

	x = 0;
	while (x < stock->linenum)
	{
		free(proj[x]);
		proj[x] = NULL;
		x++;
	}
	free (proj);
	x = 0;
	while (x < stock->linenum)
	{
		free(stock->index[x]);
		stock->index[x] = NULL;
		x++;
	}
	free(stock->index);
	free(stock);
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
	xpoint = check_lowest_xpoint(proj, stock) - 500;
	ypoint = check_lowest_ypoint(proj, stock) - 200;
	if (ypoint > 0)
		ypoint = 0;
	if (xpoint > 0)
		xpoint = 0;
	while (y < stock->linenum - 1)
	{
		x = 0;
		while (x < stock->index[0][0] - 1)
		{
			stock->color = ft_color(proj[y][x].height);
			draw_lines(proj[y][x].x-xpoint, proj[y][x].y-ypoint, proj[y][x+1].x-xpoint, proj[y][x+1].y-ypoint, stock);
			draw_lines(proj[y][x].x-xpoint, proj[y][x].y-ypoint, proj[y+1][x].x-xpoint, proj[y+1][x].y-ypoint, stock);
			x++;
		}
		y++;
	}
	ft_freeproj(proj, stock);
	mlx_put_image_to_window(stock->mlx, stock->window, stock->image, 0, 0);
	mlx_key_hook(stock->window, key_hook, 0);
	mlx_loop(stock->mlx);
	return (1);
}