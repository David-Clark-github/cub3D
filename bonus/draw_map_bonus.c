/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:47:13 by dclark            #+#    #+#             */
/*   Updated: 2021/04/18 12:59:16 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	draw_square_bonus(int x, int y, int color, t_data *data)
{
	int	y_st;
	int	x_st;

	y_st = y - 1;
	while (++y_st < y + 15)
	{
		x_st = x - 1;
		while (++x_st < x + 15)
			my_put_pixel(&data->img, x_st, y_st, color);
	}
}

void	draw_map_bonus(char **map, t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ' ')
				draw_square_bonus(x * 15, y * 15, trgb(0, 0, 0, 0), data);
			else if (map[y][x] == '0')
				draw_square_bonus(x * 15, y * 15, trgb(0, 200, 200, 200)\
				, data);
			else if (map[y][x] == '1')
				draw_square_bonus(x * 15, y * 15, trgb(0, 125, 125, 125)\
				, data);
			else if (map[y][x] == '2')
				draw_square_bonus(x * 15, y * 15, trgb(0, 200, 0, 0), data);
		}
	}
}
