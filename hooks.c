/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:06:17 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/24 17:43:39 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_stock *stock)
{
	if (keycode == 53)
		ft_exit_finish("Exit Success", 2, stock);
	if (keycode == 123)
	{
		printf("caca");
		stock->x++;
	}
	if (keycode == 126)
	{
		printf("caca");
		stock->y++;
	}
	if (keycode == 124)
	{
		printf("caca");
		stock->x--;
	}
	if (keycode == 125)
	{
		printf("caca");
		stock->y--;
	}
	return (0);
}