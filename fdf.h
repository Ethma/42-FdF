/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:22:59 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/12 16:34:12 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef	struct		s_points
{
	int		x;
	int		y;
	int		z;
	char	**tab;
}					t_points;

typedef struct		s_stock
{
	int			**index;
	char		**tab;
	int			**tabint;
	int			linenum;
}					t_stock;

typedef	struct		s_proj
{
	int			x;
	int			y;
	int			z;
}					t_proj;

t_stock	*fdf_start(int fd, const char *str);
void	ft_projections(t_stock	*stock, t_proj **proj);
t_proj	**ft_getheight(t_stock *stock);
#endif