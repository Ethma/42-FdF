/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:22:59 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/02 15:00:55 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>

void	entry_check(int fd);

typedef	struct		s_points
{
	int x;
	int y;
	int z;
}					t_points;

typedef struct		s_stock
{
	t_points	**points;
}					t_stock;

#endif