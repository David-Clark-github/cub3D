/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:13:10 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 15:23:44 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	parsing_master(t_data *data)
{
	data->map.map = data->elem_err.map_err.map;
	data->map.width = data->elem_err.map_err.x_max;
	data->map.height = data->elem_err.map_err.y_max;
	get_res(data->raw_cub_l[data->elem_l.res], &data->res);
	get_color(data->raw_cub_l[data->elem_l.floor], &data->floor);
	get_color(data->raw_cub_l[data->elem_l.ceil], &data->ceil);
	get_player(&data->player, data->map.map);
	data->win.mlx = mlx_init();
//	printf("\nmlx = %p\n", data->win.mlx);
	data->win.win = mlx_new_window(data->win.mlx, data->res.x, data->res.y, "cub3D");
//	printf("win = %p\n", data->win.win);
	data->img_a.img = mlx_new_image(data->win.mlx, data->res.x, data->res.y);
//	printf("img = %p\n", data->img_a.img);
	data->img_a.addr = mlx_get_data_addr(data->img_a.img,
											&data->img_a.bpp,
											&data->img_a.line_l,
											&data->img_a.endian);
//	printf("addr = %p\n", data->img_a.addr);
}
