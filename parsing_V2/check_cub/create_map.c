/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:18:40 by dclark            #+#    #+#             */
/*   Updated: 2021/02/26 13:40:21 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <stdio.h>

/*
** the lqst line of map end with a 0
*/

void	create_map(t_map *map, char **s_line)
{
	int i = 0;
	int	reste;
	int	y_l = 0;

	map->map = malloc(sizeof(char *) * map->y_max + 1);
	while (i < map->y_max)
	{
		map->map[i] = malloc(sizeof(char) * map->x_max);
		i++;;
	}
	i = 0;
	while (y_l < map->y_max - 1)
	{
		reste = map->x_max - ft_strlen(s_line[y_l + map->map_st]);
		while (s_line[y_l + map->map_st][i])
		{
			map->map[y_l][i] = s_line[y_l + map->map_st][i];
			i++;
		}
		while (reste--)
			map->map[y_l][i++] = ' ';

		i = 0;
		y_l++;
	}
	map->map[y_l] = 0;
}
