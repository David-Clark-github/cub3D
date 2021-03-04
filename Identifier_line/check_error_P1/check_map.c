/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:24:39 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 15:35:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_map(t_map_err *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		while (x < map->x_max)
		{
			if (map->map[y][x] == ' ')
			if (map->map[y][x] == '0')
			if (map->map[y][x] == '1')
			if (map->map[y][x] == '2')
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'\
					|| map->map[y][x] == 'W' || map->map[x][y] == 'E')
			x++;
		}
		y++;
	}
}
