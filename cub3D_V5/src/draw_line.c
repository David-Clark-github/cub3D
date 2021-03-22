/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:04:32 by dclark            #+#    #+#             */
/*   Updated: 2021/03/22 12:03:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	draw_line2(int xa, int ya, int xb, int yb, t_data *data)
{
	int	dx;
	int	dy;
	int	y;
	int	x_loop;

	dx = xb - xa;
	dy = yb - ya;
	x_loop = xa;
	while (x_loop++ < xb)
	{
		y = ya + dy * (x_loop - xa) / dx;
		my_put_pixel(&data->img_a, x_loop, y, create_trgb(0,0,0,255));
	}
}

void	draw_line(int xa, int ya, int xb, int yb, t_data *data)
{
	int	dx;
	int	dy;
	int	y;
	int	x_loop;

	if (xb >= xa)
	{
		dx = xb - xa;
		dy = yb - ya;
		x_loop = xa;
		while (x_loop++ < xb)
		{
			y = ya + dy * (x_loop - xa) / dx;
			my_put_pixel(&data->img_a, x_loop, y, create_trgb(0,0,0,255));
		}
	}
	else
		draw_line2(xb, yb, xa, ya, data);
}
