/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:25:28 by dclark            #+#    #+#             */
/*   Updated: 2021/04/12 16:28:02 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	move(int keycode, void *param)
{
	t_data *data;

	data = param;
	ceil_floor_to_img(data);
	if (keycode == ESC)
		ft_error("Fin de cub3D", 0, data);
	else if (keycode == RT_LEFT)
		rotate_left(&data->ply);
	else if (keycode == RT_RIGHT)
		rotate_right(&data->ply);
	else if (keycode == FORWARD)
		forward(&data->ply, &data->map);
	else if (keycode == BACKWARD)
		backward(&data->ply, &data->map);
	algo(data);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img.img, 0, 0);
	return (1);
}
