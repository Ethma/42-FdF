/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:02:08 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/11 15:31:21 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_projections(t_stock	*stock)
{
	t_proj	**proj;
	int		x;
	int		y;
	int		k;

	y = 0;
	while (y < ft_intrlen(stock->tabint))
	{
		x = 0;
		while (x < stock->index[y][0])
		{
			proj[y][x].x = x ;
			x++;
		}
		y++;
	}
}