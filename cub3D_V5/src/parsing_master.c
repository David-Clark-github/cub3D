/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:13:10 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 12:22:52 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	parsing_master(t_data *data)
{
	data->map.map = data->elem_err.map_err.map;
	data->map.width = data->elem_err.map_err.x_max;
	data->map.height = data->elem_err.map_err.y_max;
	data->win.mlx = mlx_init();
	data->win.win = mlx_new_window(data->win.mlx, 940, 720, "cub3D");
	data->img_a.img = mlx_new_image(data->win.mlx, data->res.x, data->res.y);
	data->img_a.addr = mlx_get_data_addr(&data->img_a.img,
											&data->img_a.bpp,
											&data->img_a.line_l,
											&data->img_a.endian);
	get_res(data->raw_cub_l[data->elem_l.res], &data->res);
}
