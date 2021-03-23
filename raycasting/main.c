#include "include.h"

int main(void)
{
	t_ray	ray;

	ray.pos_x = 4.5;
	ray.pos_y = 4.5;
	ray.dir_x = -1.0;
	ray.dir_y = 0.0;
	ray.ray_dir_x = ray.dir_x;
	ray.ray_dir_y = ray.dir_y;
	ray.map_x = (int)ray.pos_x;
	ray.map_y = (int)ray.pos_y;
	ray.delta_dist_x = sqrt(1 + (ray.dir_y * ray.dir_y) / (ray.dir_x * ray.dir_x));	
	ray.delta_dist_y = sqrt(1 + (ray.dir_x * ray.dir_x) / (ray.dir_y * ray.dir_y));	
	if (ray.dir_x < 0)
	{
		ray.step_x = -1;
		ray.side_dist_x = (ray.pos_x - ray.map_x) * ray.delta_dist_x;
	}
	else
	{
		ray.step_x = 1;
		ray.side_dist_x = (ray.pos_x  + 1.0 - ray.map_x) * ray.delta_dist_x;
	}
	if (ray.dir_y < 0)
	{
		ray.step_y = -1;
		ray.side_dist_y = (ray.pos_y - ray.map_y) * ray.delta_dist_y;
	}
	else
	{
		ray.step_y = 1;
		ray.side_dist_y = (ray.pos_y  + 1.0 - ray.map_y) * ray.delta_dist_y;
	}
	while (ray.hit == 0)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_dist_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist_y += ray.delta_dist_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (map[ray.map_y][ray.map_x] == 1)
			ray.hit = 1;
	}
	if (ray.side == 0)
		ray.perpwalldist = (ray.map_x - ray.pos_x + (1 - ray.step_x) / 2) / ray.dir_x;
	else
		ray.perpwalldist = (ray.map_y - ray.pos_y + (1 - ray.step_y) / 2) / ray.dir_y;

	printf("len = %f\n", ray.perpwalldist);
}
