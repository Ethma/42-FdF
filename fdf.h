/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:22:59 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/25 18:49:58 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define WIN_H 1080
# define WIN_W 1920
# define BUFFF_SIZE 1000000

typedef struct		s_stock
{
	int				index;
	char			**tab;
	int				**tabint;
	int				linenum;
	void			*mlx;
	void			*window;
	void			*image;
	int				color;
	int				xpoint;
	int				ypoint;
	int				y;
	int				x;
	double			projy;
	int				y1;
}					t_stock;

typedef	struct		s_proj
{
	double			x;
	double			y;
	double			z;
	double			height;
}					t_proj;

int					fdf_start(int fd, const char *str);
t_proj				**ft_projections(t_stock *stock, t_proj **proj);
t_proj				**ft_getheight(t_stock *stock);
int					draw_points(t_proj **proj, t_stock *stock);
t_proj				**ft_projections(t_stock *stock, t_proj **proj);
void				mlx_pixel_put_to_image(void *img, int x, int y, int color);
void				draw_lines(int x1, int x2, int y2, t_stock *stock);
int					check_lowest_xpoint(t_proj **proj, t_stock *stock);
int					check_lowest_ypoint(t_proj **proj, t_stock *stock);
int					check_highest_ypoint(t_proj **proj, t_stock *stock);
int					check_highest_xpoint(t_proj **proj, t_stock *stock);
int					ft_color(double z);
int					key_hook(int keycode, t_stock *stock);
int					ft_exit(char *str, int i);
int					ft_exit_finish(char *str, int i, t_stock *stock);
void				fdf_end(t_proj **proj, t_stock *stock);
void				ft_freeproj(t_proj **proj, t_stock *stock);
void				keykey(int i, t_stock *stock);
#endif
