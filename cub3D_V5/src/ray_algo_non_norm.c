/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_algo_non_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:41:37 by dclark            #+#    #+#             */
/*   Updated: 2021/03/25 15:22:35 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"



void	algo_ray(t_data *data)
{
	data->ray.hit = 0;
	data->ray.lineheight = 0;
	data->ray.perpwalldist = 0;
	data->ray.pos_x = data->player.pos_x + 0.5;
	data->ray.pos_y = data->player.pos_y + 0.5;
	data->ray.dir_x = data->player.pdx;
	data->ray.dir_y = data->player.pdy;
	data->ray.plan_x = data->ray.dir_x * 0.66;
	data->ray.plan_y = data->ray.dir_y * 0.66;
	data->ray.camera_x = 2.0 * 1.0 / 1.0 - 1.0;
	data->ray.ray_dir_x = data->ray.dir_x + data->ray.plan_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->ray.dir_y + data->ray.plan_y * data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	data->ray.delta_dist_x = sqrt(1 + (data->ray.ray_dir_y * data->ray.ray_dir_y) / 
										(data->ray.ray_dir_x * data->ray.ray_dir_x));
	data->ray.delta_dist_y = sqrt(1 + (data->ray.ray_dir_x * data->ray.ray_dir_x) /
										(data->ray.ray_dir_y * data->ray.ray_dir_y));
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.pos_x - data->ray.map_x) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.pos_x + 1.0 - data->ray.map_x) * data->ray.delta_dist_y;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.pos_y - data->ray.map_y) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.pos_y + 1.0 - data->ray.map_y) * data->ray.delta_dist_y; 
	}
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if ((data->ray.map_x >= 0 && data->ray.map_x < data->map.width) && 
			(data->ray.map_y >= 0 && data->ray.map_y < data->map.height))
		{
			if (data->map.map[data->ray.map_y][data->ray.map_x] == '1')
				data->ray.hit = 1;
		}
		else
		{
			data->ray.hit = 1;
			//data->ray.side_dist_y -= data->ray.delta_dist_y;
			//data->ray.side_dist_x -= data->ray.delta_dist_x;
		}
	}
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.map_x - data->ray.pos_x + (1 - data->ray.step_x) / 2) / data->ray.ray_dir_x;
	else
		data->ray.perpwalldist = (data->ray.map_y - data->ray.pos_y + (1 - data->ray.step_y) / 2) / data->ray.ray_dir_y;
	//printf("perpWallDist = %f\n", data->ray.perpwalldist * SIZE);
	//printf("linelenght ? %f\n", sqrt(pow(data->ray.side_dist_x, 2.0) + pow(data->ray.side_dist_y, 2.0)));
}
