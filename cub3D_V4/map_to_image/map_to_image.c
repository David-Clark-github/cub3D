/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:38:09 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 11:16:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_to_image.h"


t_map_img	*map_to_image(t_map *map, t_win *win)
{
	t_map_img	*map_i;

	map_i = malloc(sizeof(t_map_img));
	map_i->width = map->width * 10;
	map_i->height = map->height * 10;
	map_i->img = mlx_new_image(win->mlx, map_i->width, map_i->height);

}
