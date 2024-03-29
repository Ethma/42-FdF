/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabessir <mabessir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:26:04 by mabessir          #+#    #+#             */
/*   Updated: 2017/11/15 11:34:50 by Mendy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_space(size_t i, size_t j, const char *s)
{
	while (i != j)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
				s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			return (1);
		i++;
		j--;
	}
	return (0);
}
