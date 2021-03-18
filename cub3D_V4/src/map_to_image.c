/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1021/03/15 10:38:09 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 14:38:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "parsing.h"

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

void	map_to_image(t_img_a *img_a, t_map *map, t_win *win)
{
	int			y;
	int			x;

	img_a->width = map->width * 10;
	img_a->height = map->height * 10;
	img_a->img = mlx_new_image(win->mlx, img_a->width, img_a->height);	
	img_a->addr = mlx_get_data_addr(img_a->img, &img_a->bpp, &img_a->line_l, &img_a->endian);
	while (y < map->height)
	{
		while (x < map->width)
		{
			draw_square(img_a, x * 10, y * 10, 10, color_r(map->map[y][x]));
			x++;
		}
		x = 0;
		y++;
	}
}
