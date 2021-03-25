/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:45:56 by dclark            #+#    #+#             */
/*   Updated: 2021/03/25 15:32:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	move(int keycode, void *param)
{
	t_data	*data;
//	double	old_pa;

	data = param;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == ROTATE_LEFT)
		rotate_left(data);
	if (keycode == ROTATE_RIGHT)
		rotate_right(data);
	if (keycode == FORWARD)
		forward(data);
	if (keycode == BACKWARD)
		backward(data);
	if (keycode == RIGHT)
		go_right(data);
	if (keycode == LEFT)
		go_left(data);
	map_to_image(&data->img_a, &data->map);
	//my_put_pixel(&data->img_a, data->player.pos_x, data->player.pos_y, create_trgb(0,0,0,255));
	algo_ray(data);
	draw_square(&data->img_a, 
				data->player.pos_x , 
				data->player.pos_y, 
				SIZE / 2, 
				create_trgb(0,0,0,255));
	draw_line(data->player.pos_x,
				data->player.pos_y,
				data->player.pos_x + data->player.pdx * 4,
				data->player.pos_y + data->player.pdy * 4,
				data);
	/*draw_line(data->player.pos_x,
				data->player.pos_y,
				data->ray.side_dist_x, data->ray.side_dist_y, data);*/
//	ray_line_h(data);
/*	draw_square(&data->img_a, 
				data->player.pos_x + SIZE / 8 + data->player.pdx * 4, 
				data->player.pos_y + SIZE / 8 + data->player.pdy * 4, 
				SIZE / 4, 
				create_trgb(0,255,0,0));*/
	printf("pos_x = %f\n", data->player.pos_x);
	printf("pos_y = %f\n", data->player.pos_y);
	printf("pa = %f\n", data->player.pa);
	printf("side_dist_x = %f\n", data->ray.side_dist_x);
	printf("side_dist_y = %f\n", data->ray.side_dist_y);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img_a.img, 0, 0);
	mlx_loop(data->win.mlx);
	return (1);
}
