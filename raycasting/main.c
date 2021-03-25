#include "include.h"

int		move(int keycode, void *param)
{
	t_ray	*ray;

	ray = param;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	if (keycode == 65363)
	{
		ray.
	}
}

void	algo(t_ray *ray)
{
	//t_ray	ray;

	ray->hit = 0;
	ray->pos_x = 1.5;
	ray->pos_y = 3.5;
	ray->dir_x = 1.0;
	ray->dir_y = -0.7;
	ray->plan_x = ray->dir_x * 0.66;
	ray->plan_y = ray->dir_y * 0.66;
	ray->camera_x = 0.0;//2.0 * 1.0 / 1.0 - 1.0;
	ray->ray_dir_x = ray->dir_x + ray->plan_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plan_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = sqrt(1 + (ray->ray_dir_y * ray->ray_dir_y) / (ray->ray_dir_x * ray->ray_dir_x));	
	ray->delta_dist_y = sqrt(1 + (ray->ray_dir_x * ray->ray_dir_x) / (ray->ray_dir_y * ray->ray_dir_y));	
	//ray->delta_dist_x = (ray->ray_dir_y == 0) ? 0 : ((ray->ray_dir_x == 0) ? 1 : fabs(1 / ray->ray_dir_x));
	//ray->delta_dist_y = (ray->ray_dir_x == 0) ? 0 : ((ray->ray_dir_y == 0) ? 1 : fabs(1 / ray->ray_dir_y));
	//printf("delta dist y = %f\n", ray->delta_dist_y);
	//printf("delta dist x = %f\n", ray->delta_dist_x);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->pos_x  + 1.0 - ray->map_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1->0 - ray->pos_y) * ray->delta_dist_y;
	}
	//printf("side y = %f\n", ray->side_dist_y);
	//printf("side x = %f\n", ray->side_dist_x);
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == 1)
			ray->hit = 1;
	}
//	printf("side y = %f\n", ray->side_dist_y);
//	printf("side x = %f\n", ray->side_dist_x);
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perpwalldist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;

	printf("len = %f\n", ray->perpwalldist);
}

int main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 100, 100, "test Raycasting");
	mlx_hook()
	algo();
	return (0);
}
