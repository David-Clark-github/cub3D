/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_line_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:21:19 by dclark            #+#    #+#             */
/*   Updated: 2021/03/22 15:06:07 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ray_line_h(t_data *data)
{
	data->ray.ra = data->player.pa;
	for (data->ray.r = 0; data->ray.r < 1; data->ray.r++)
	{
		data->ray.dof = 0;
		double aTan = -1 / tan(data->ray.ra);
		if (data->ray.ra > PI)
		{
			data->ray.ry = (((int)data->player.pos_y>>5)<<5) - 0.0001;
			data->ray.rx = (data->player.pos_y - data->ray.ry) * aTan + data->player.pos_x;
			data->ray.yo -= 32;
			data->ray.xo -= data->ray.yo * aTan;
		}
		if (data->ray.ra < PI)
		{
			data->ray.ry = (((int)data->player.pos_y>>5)<<5) + 32;
			data->ray.rx = (data->player.pos_y - data->ray.ry) * aTan + data->player.pos_x;
			data->ray.yo += 32;
			data->ray.xo -= data->ray.yo * aTan;
		}
		if (data->ray.ra == 0 || data->ray.ra == PI)
		{
			data->ray.rx = data->player.pos_x;
			data->ray.ry = data->player.pos_y;
			data->ray.dof = data->map.height;
		}
		while (data->ray.dof < data->map.height)
		{
			data->ray.mx = (int)(data->ray.rx)>>5;
			data->ray.my = (int)(data->ray.ry)>>5;
			data->ray.mp = data->ray.my * data->map.width + data->ray.mx;
			if (data->map.map[data->ray.my][data->ray.mx] == '1' && 
				data->ray.my < data->map.height && 
				data->ray.mx < data->map.width)
			{
				data->ray.dof = data->map.height;
			}
			else
			{
				data->ray.rx += data->ray.xo;
				data->ray.ry += data->ray.yo;
				data->ray.dof += 1;
			}
		}
		draw_line(data->player.pos_x, data->player.pos_y, 
				data->ray.rx, data->ray.ry, data);
	}
}
