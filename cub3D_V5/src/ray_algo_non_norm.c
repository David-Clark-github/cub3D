/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_algo_non_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:41:37 by dclark            #+#    #+#             */
/*   Updated: 2021/03/24 17:00:13 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	algo_ray(t_data *data)
{
	data->ray.hit = 0;
	data->ray.pos_x = data->player.pos_x;
	data->ray.pos_y = data->player.pos_y;
	data->ray.dir_x = data->player.dir_x;
	data->ray.dir_y = data->player.dir_y;
	data->ray.plan_x = (ft);
	data->ray.plan_y = (ft);
	data->ray.camera_x = (ft);
	data->ray.ray_dir_x = data->ray.dir_x + data->ray.plan_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->ray.dir_y + data->ray.plan_y * data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	data->ray.delta_dist_x = sqrt(1 + (data->ray.ray_dir_y * data->ray.ray_dir_y) / data->);
	data->ray.delta_dist_y = sqrt(1 + ());

}
