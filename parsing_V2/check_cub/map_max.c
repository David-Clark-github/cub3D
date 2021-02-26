/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:32:22 by dclark            #+#    #+#             */
/*   Updated: 2021/02/25 14:32:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	map_max(t_map *map, char **s_line)
{
	int	y;

	y = 0;
	map->x_max = 0;
	map->y_max = 0;
	while (s_line[y + map->map_st])
	{
		if (ft_strlen(s_line[y + map->map_st]) > map->x_max)
			map->x_max = ft_strlen(s_line[y + map->map_st]);
		y++;
	}
	map->y_max = y;
}
