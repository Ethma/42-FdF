/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:22:59 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/15 15:20:44 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define WIN_H 1000
# define WIN_W 1000
typedef	struct		s_points
{
	int		x;
	int		y;
}					t_points;

typedef struct		s_stock
{
	int			**index;
	char		**tab;
	int			**tabint;
	int			linenum;
	void		*mlx;
	void		*window;
	void		*image;
	int			lowest_point;
	int			highest_point;
}					t_stock;

typedef	struct		s_proj
{
	double		x;
	double		y;
	double		z;
}					t_proj;

int		fdf_start(int fd, const char *str);
t_proj	**ft_projections(t_stock	*stock, t_proj **proj);
t_proj	**ft_getheight(t_stock *stock);
int		draw_points(t_proj **proj, t_stock *stock);
t_proj	**ft_projections(t_stock *stock, t_proj **proj);
void	mlx_pixel_put_to_image(void *img, int x, int y, int color);
void	draw_lines(int x1, int y1, int x2, int y2, t_stock *stock);
#endif