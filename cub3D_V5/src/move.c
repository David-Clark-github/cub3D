/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:45:56 by dclark            #+#    #+#             */
/*   Updated: 2021/03/21 13:23:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	move(int keycode, void *param)
{
	t_data	*data;
	double	old_pa;

	data = param;
	map_to_image(&data->img_a, &data->map);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == ROTATE_LEFT)
	{
		data->player.pa -= 0.1;
		if (data->player.pa < 0)
			data->player.pa += 2 * PI;
		data->player.pdx = cosf(data->player.pa) * 5;
		data->player.pdy = sinf(data->player.pa) * 5;
	}
	if (keycode == ROTATE_RIGHT)
	{
		data->player.pa += 0.1;
		if (data->player.pa > 2 * PI)
			data->player.pa -= 2 * PI;
		data->player.pdx = cosf(data->player.pa) * 5;
		data->player.pdy = sinf(data->player.pa) * 5;
	}
	if (keycode == FORWARD)
	{
		data->player.pos_x += data->player.pdx;
		data->player.pos_y += data->player.pdy;
	}
	if (keycode == BACK)
	{
		data->player.pos_x -= data->player.pdx;
		data->player.pos_y -= data->player.pdy;
	}
	if (keycode == RIGHT)
	{
		old_pa = data->player.pa;
		data->player.pa += (2 * PI / 4);
		if (data->player.pa > (2 * PI))
			data->player.pa -= (2 * PI);
		data->player.pdx = cosf(data->player.pa) * 5;
		data->player.pdy = sinf(data->player.pa) * 5;
		data->player.pos_x += data->player.pdx;
		data->player.pos_y += data->player.pdy;
		data->player.pa = old_pa;
		data->player.pdx = cosf(data->player.pa) * 5;
		data->player.pdy = sinf(data->player.pa) * 5;
	}
	if (keycode == LEFT)
	{
		old_pa = data->player.pa;
		data->player.pa -= (2 * PI / 4);
		if (data->player.pa < 0)
			data->player.pa += (2 * PI);
		data->player.pdx = cosf(data->player.pa) * 5;
		data->player.pdy = sinf(data->player.pa) * 5;
		data->player.pos_x += data->player.pdx;
		data->player.pos_y += data->player.pdy;
		data->player.pa = old_pa;
		data->player.pdx = cosf(data->player.pa) * 5;
		data->player.pdy = sinf(data->player.pa) * 5;
	}
	//my_put_pixel(&data->img_a, data->player.pos_x, data->player.pos_y, create_trgb(0,0,0,255));
	draw_square(&data->img_a, 
				data->player.pos_x , 
				data->player.pos_y, 
				SIZE / 2, 
				create_trgb(0,0,0,255));
	draw_square(&data->img_a, 
				data->player.pos_x + SIZE / 8 + data->player.pdx * 4, 
				data->player.pos_y + SIZE / 8 + data->player.pdy * 4, 
				SIZE / 4, 
				create_trgb(0,255,0,0));
	printf("pos_x = %f\n", data->player.pos_x);
	printf("pos_y = %f\n", data->player.pos_y);
	printf("pa = %f\n", data->player.pa);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img_a.img, 0, 0);
	mlx_loop(data->win.mlx);
	return (1);
}
