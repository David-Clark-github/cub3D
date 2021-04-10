/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:29:10 by dclark            #+#    #+#             */
/*   Updated: 2021/04/10 15:21:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	exec(t_data *data)
{
	algo(data);
	data->win.win = mlx_new_window(data->win.mlx, data->win.width,
	data->win.height, "cub3D");
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img.img, 0, 0);
	mlx_hook(data->win.win, 2, 1L<<0, move, data);
	mlx_loop(data->win.mlx);
}
