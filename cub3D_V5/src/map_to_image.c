/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:09:00 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 15:27:18 by dclark           ###   ########.fr       */
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

void	map_to_image(t_img_a *img_a, t_map *map)
{
	int			y;
	int			x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			draw_square(img_a, x * SIZE, y * SIZE, SIZE, color_r(map->map[y][x]));
			x++;
		}
		y++;
	}
}
