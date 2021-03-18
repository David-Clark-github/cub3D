/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cara_voisin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:15:09 by user42            #+#    #+#             */
/*   Updated: 2021/03/18 10:29:17 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_err.h"

static int	ztnsew(char c)
{
	if (c == '0' || c == '2')
		return (1);
	if (c == 'N' || c == 'S')
		return (1);
	if (c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	voisin(t_map_err *map, int x, int y)
{
	if (x == 0 || x == map->x_max - 1)
		return (-1);
	if (y == 0 || y == map->y_max - 1)
		return (-1);
	if (map->map[y][x + 1] == ' ' || map->map[y][x - 1] == ' ')
		return (-1);
	if (map->map[y + 1][x] == ' ' || map->map[y - 1][x] == ' ')
		return (-1);
	if (map->map[y + 1][x - 1] == ' ' || map->map[y - 1][x - 1] == ' ')
		return (-1);
	if (map->map[y + 1][x + 1] == ' ' || map->map[y - 1][x + 1] == ' ')
		return (-1);
	return (1);
}

int	cara_voisin(t_map_err *map) 
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y])
	{
		while (map->map[y][x])
		{
			if (ztnsew(map->map[y][x]))
				if (voisin(map, x, y) == -1)
					return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
