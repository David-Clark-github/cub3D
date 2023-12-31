/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:25:28 by dclark            #+#    #+#             */
/*   Updated: 2021/04/20 14:54:57 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	move_bonus(int keycode, t_data *data)
{
	if (keycode == D_MAP)
		data->d_map *= -1;
	if (data->d_map == 1)
		draw_map_bonus(data->map.map, data);
}

int			move(int keycode, void *param)
{
	t_data *data;

	data = param;
	if (keycode == ESC)
		ft_error("Fin de cub3D_bonus", 0, data);
	else if (keycode == RT_LEFT)
		rotate_left(&data->ply);
	else if (keycode == RT_RIGHT)
		rotate_right(&data->ply);
	else if (keycode == FORWARD)
		forward(&data->ply, &data->map);
	else if (keycode == BACKWARD)
		backward(&data->ply, &data->map);
	else if (keycode == CRABE_L)
		crabe_left(&data->ply, data->map.map);
	else if (keycode == CRABE_R)
		crabe_right(&data->ply, data->map.map);
	floor_ceil_texture(&data->f_c, data);
	algo(data);
	move_bonus(keycode, data);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img.img, 0, 0);
	return (1);
}
