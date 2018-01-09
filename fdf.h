/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:22:59 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/09 12:54:45 by mabessir         ###   ########.fr       */
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
	t_points	**points;
	int			x;
	int			y;
	int			z;
	int			index;
}					t_stock;

void	entry_check(int fd);
int		fdf_start(int fd, const char *str);

#endif