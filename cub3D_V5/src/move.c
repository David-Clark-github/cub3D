/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:45:56 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 15:42:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	move(int keycode, void *param)
{
	t_data	*data;

	data = param;
	map_to_image(&data->img_a, &data->map);
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
	//my_put_pixel(&data->img_a, data->player.pos_x, data->player.pos_y, create_trgb(0,0,0,255));
	draw_square(&data->img_a, data->player.pos_x , data->player.pos_y, SIZE / 2, create_trgb(0,0,0,255));
	printf("pos_x = %f\n", data->player.pos_x);
	printf("pos_y = %f\n", data->player.pos_y);
	printf("pa = %f\n", data->player.pa);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img_a.img, 0, 0);
	mlx_loop(data->win.mlx);
	return (1);
}
