/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:39:47 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 13:03:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_map(t_mapou *map)
{
	int	y;

	y = -1;
	if (map->map != NULL)
	{
/*		while (map->map_h--)
			free(map->map[map->map_h]);
		free(map->map);*/
		while (++y < map->map_h)
			free(map->map[y]);
		free(map->map);
	}
}
