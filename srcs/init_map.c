/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:42:12 by dclark            #+#    #+#             */
/*   Updated: 2021/04/09 10:43:41 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_map(t_mapou *map)
{
	map->map = NULL;
	map->map_h = 0;
	map->map_w = 0;
	map->sp_num = 0;
}
