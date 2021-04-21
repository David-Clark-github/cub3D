/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:47:13 by dclark            #+#    #+#             */
/*   Updated: 2021/04/21 13:09:11 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	draw_square_bonus(int x, int y, int color, t_data *data)
{
	int	y_st;
	int	x_st;

	y_st = y - 1;
	while (++y_st < y + 10)
	{
		x_st = x - 1;
		while (++x_st < x + 10)
			my_put_pixel(&data->img, x_st, y_st, color);
	}
}

static int	limits(t_data *data)
{
	if (data->win.width < 940)
		return (1);
	if (data->win.height < 720)
		return (1);
	return (0);
}

void		draw_map_bonus(char **map, t_data *data)
{
	int	y;
	int	x;

	y = -1;
	if (limits(data) == 1)
		return ;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == ' ')
				draw_square_bonus(x * 10, y * 10, trgb(0, 0, 0, 0), data);
			else if (map[y][x] == '0')
				draw_square_bonus(x * 10, y * 10, trgb(0, 200, 200, 200)\
				, data);
			else if (map[y][x] == '1')
				draw_square_bonus(x * 10, y * 10, trgb(0, 125, 125, 125)\
				, data);
			else if (map[y][x] == '2')
				draw_square_bonus(x * 10, y * 10, trgb(0, 200, 0, 0), data);
		}
	}
}
