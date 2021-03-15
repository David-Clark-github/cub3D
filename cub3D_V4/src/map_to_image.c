/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:38:09 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 14:19:14 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		color_r(char c)
{
	if (c == ' ')
		return (create_trgb(SPACE));
	if (c == '0')
		return (create_trgb(EMPTY));
	if (c == '1')
		return (create_trgb(WALL));
	if (c == '2')
		return (create_trgb(SPRITE));
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (create_trgb(CARA));
	return (123456789);
}

void	map_to_image(t_map_img *map_i, t_map *map, t_win *win)
{
	int			y;
	int			x;

	map_i->width = map->width * 20;
	map_i->height = map->height * 20;
	map_i->img = mlx_new_image(win->mlx, map_i->width, map_i->height);	
	map_i->addr = mlx_get_data_addr(map_i->img, &map_i->bpp, &map_i->line_l, &map_i->endian);
	while (y < map->height)
	{
		while (x < map->width)
		{
			draw_square(map_i, x * 20, y * 20, 20, color_r(map->map[y][x]));
			x++;
		}
		x = 0;
		y++;
	}
}
