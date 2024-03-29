/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:18:16 by mabessir          #+#    #+#             */
/*   Updated: 2018/01/12 14:55:29 by mabessir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intrlen(int **tab, int size)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
		size = i;
	}
	return (i);
}
