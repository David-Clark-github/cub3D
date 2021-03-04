/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_player_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:40:39 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 15:46:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	init(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	one_player_map(char **map)
{
	int	y;
	int	x;
	int	res;

	init(&x, &y, &res);
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S')
				res++;
			if (map[y][x] == 'W' || map[y][x] == 'E')
				res++;
			x++;
		}
		x = 0;
		y++
	}
	if (res != 1)
		return (-1);
	return (1);
}
