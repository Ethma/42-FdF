/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:02:08 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/25 18:49:18 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define X stock->x
#define Y stock->y
#define PROJY (proj[Y][X].y - stock->ypoint)

t_proj			**ft_getheight(t_stock *stock)
{
	t_proj	**proj;
	int		x;
	int		y;

	if (!(proj = (t_proj **)malloc(sizeof(t_proj *) * stock->linenum)))
		ft_exit("Malloc ERROR", 1);
	y = 0;
	while (y < stock->linenum)
	{
		if (!(proj[y] = (t_proj *)malloc(sizeof(t_proj) * stock->index)))
			ft_exit("Malloc ERROR", 1);
		x = -1;
		while (++x < stock->index)
		{
			proj[y][x].z = stock->tabint[y][x];
			proj[y][x].height = stock->tabint[y][x];
			proj[y][x].z = proj[y][x].z * -1;
			proj[y][x].x = x * ((WIN_W / 2) / stock->index);
			proj[y][x].y = y * ((WIN_H / 2) / stock->linenum);
			proj[y][x].z = proj[y][x].z * ((WIN_W / 2) / stock->index);
		}
		y++;
	}
	ft_freetabint2d(stock->tabint, stock->linenum);
	return (proj);
}

t_proj			**ft_projections(t_stock *stock, t_proj **proj)
{
	int		x;
	int		y;
	int		k;

	y = 0;
	while (y < stock->linenum)
	{
		x = 0;
		while (x < stock->index)
		{
			proj[y][x].x = (0.5 * proj[y][x].x) - (0.75 * proj[y][x].y);
			proj[y][x].y = proj[y][x].z + ((0.5 / 2) * proj[y][x].x) +
			((0.75 / 2) * proj[y][x].y);
			x++;
		}
		y++;
	}
	return (proj);
}

int				ft_color(double z)
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

static void		xypoint(t_proj **proj, t_stock **stock)
{
	(*stock)->mlx = mlx_init();
	(*stock)->window = mlx_new_window((*stock)->mlx, WIN_W, WIN_H, "FDF");
	(*stock)->image = mlx_new_image((*stock)->mlx, WIN_W, WIN_H);
	(*stock)->x = 0;
	(*stock)->y = 0;
	(*stock)->xpoint = check_lowest_xpoint(proj, *stock) - 500;
	(*stock)->ypoint = check_lowest_ypoint(proj, *stock) - 200;
	if ((*stock)->ypoint > 0)
		(*stock)->ypoint = 0;
	if ((*stock)->xpoint > 0)
		(*stock)->xpoint = 0;
}

int				draw_points(t_proj **proj, t_stock *stock)
{
	xypoint(proj, &stock);
	Y = -1;
	while (++Y < stock->linenum - 1)
	{
		X = -1;
		while (++X < stock->index - 1)
		{
			stock->projy = PROJY;
			stock->color = ft_color(proj[Y][X].height);
			draw_lines(proj[Y][X].x - stock->xpoint,
			proj[Y][X + 1].x - stock->xpoint,
			proj[Y][X + 1].y - stock->ypoint, stock);
			draw_lines(proj[Y][X].x - stock->xpoint,
			proj[Y + 1][X].x - stock->xpoint,
			proj[Y + 1][X].y - stock->ypoint, stock);
		}
	}
	mlx_put_image_to_window(stock->mlx, stock->window, stock->image,
	stock->x, stock->y);
	mlx_key_hook(stock->window, key_hook, stock);
	mlx_loop(stock->mlx);
	ft_freeproj(proj, stock);
	return (1);
}
