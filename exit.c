/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:27:13 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/22 16:32:46 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(char *str, int i)
{
	if (i == 2)
	{
		ft_putendl(str);
		exit(1);
	}
	if (i == 1)
	{
		ft_putendl(str);
		exit(-1);
	}
	return (0);
}