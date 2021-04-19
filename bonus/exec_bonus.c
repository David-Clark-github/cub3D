/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:29:10 by dclark            #+#    #+#             */
/*   Updated: 2021/04/19 11:59:17 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	ft_cross(void *param)
{
	t_data	*data;

	data = param;
	ft_error("Fin de cub3D_bonus", 0, data);
	return (0);
}

void		exec(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->img.img, 0, 0);
	mlx_hook(data->win.win, 2, 1L << 0, move, data);
	mlx_hook(data->win.win, 33, 1L << 17, ft_cross, data);
	mlx_loop(data->win.mlx);
}
