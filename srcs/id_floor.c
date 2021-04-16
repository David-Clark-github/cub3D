/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:35:50 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 11:53:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	id_floor(char **cub)
{
	int	i;
	int	flag;
	int	res;

	i = -1;
	flag = 0;
	while (cub[++i])
	{
		if (ft_strncmp(cub[i], "F ", 2) == 0)
		{
			res = i;
			++flag;
		}
	}
	if (flag > 1)
		ft_error("Il y plus de 1 elements de floor", 1, 0);
	if (flag == 0)
		ft_error("L'elements floor n'existe pas", 1, 0);
	return (res);
}