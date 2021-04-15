/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:35:50 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 11:55:07 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	id_map(char **cub)
{
	int	i;
	int	flag;
	int	res;

	i = -1;
	flag = 0;
	while (cub[++i] && flag == 0)
	{
		if (cub[i][0] == ' ' || cub[i][0] == '1' || cub[i][0] == '\t')
		{
			res = i;
			++flag;
		}
	}
	if (flag == 0)
		ft_error("la map n'existe pas ?! ou a une erreur", 1, 0);
	return (res);
}
