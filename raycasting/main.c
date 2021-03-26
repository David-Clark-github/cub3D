#include "include.h"

int		trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init_image(t_img *img, int width, int height, int floor, int ceil)
{
	int	middle = height / 2;
	int	x;
	int	y = 0;
	while (y < middle)
	{
		x = 0;
		while (x < width)
		{
			my_put_pixel(img, x, y, ceil);
			x++;
		}
		y++;
	}
	while (y < height)	
	{
		x = 0;
		while (x < width)
		{
			my_put_pixel(img, x, y, floor);
			x++;
		}
		y++;
	}
}

void	draw_vertical_line(t_img *img, int x, int start, int end, int color)
{
	int	i = start;
	while (i < end)
	{
		my_put_pixel(img, x, i, color);
		i++;
	}
	i = start;
	while (i < end)
	{
		my_put_pixel(img, x + 1, i, color);
		i++;
	}
	i = start;
	while (i < end)
	{
		my_put_pixel(img, x - 1, i, color);
		i++;
	}
}

int		move(int keycode, void *param)
{
	t_ray	*ray;

	ray = param;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	if (keycode == 65363)
	{
		ray->pa += 0.1;
		if (ray->pa > 2 * PI)
			ray->pa -= 2 * PI;
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
	}
	if (keycode == 65361)
	{
		ray->pa -= 0.1;
		if (ray->pa < 0)
			ray->pa += 2 * PI;
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
	}
	algo(ray);
	init_image(&ray->img, WIN_W, WIN_H, trgb(FLOOR), trgb(CEIL));
	draw_vertical_line(&ray->img, WIN_W / 2, ray->drawstart, ray->drawend, trgb(0,255,0,0));
	mlx_put_image_to_window(ray->win.mlx, ray->win.win, ray->img.img, 0, 0);
	mlx_loop(ray->win.mlx);
}

void	algo(t_ray *ray)
{
	//t_ray	ray;

	ray->hit = 0;
	ray->pos_x = 4.5;
	ray->pos_y = 3.5;
	//ray->dir_x = 1.0;
	//ray->dir_y = -0.7;
	ray->plan_x = ray->dir_x * 0.66;
	ray->plan_y = ray->dir_y * 0.66;
	printf("dir_x = %f\n", ray->dir_x);
	printf("dir_y = %f\n", ray->dir_y);
	ray->camera_x = 0.0;//2.0 * 1.0 / 1.0 - 1.0;
	ray->ray_dir_x = ray->dir_x + ray->plan_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plan_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	//ray->delta_dist_x = sqrt(1 + (ray->ray_dir_y * ray->ray_dir_y) / (ray->ray_dir_x * ray->ray_dir_x));	
	//ray->delta_dist_y = sqrt(1 + (ray->ray_dir_x * ray->ray_dir_x) / (ray->ray_dir_y * ray->ray_dir_y));	
	ray->delta_dist_x = sqrt(1 + pow(ray->ray_dir_y, 2) / pow(ray->ray_dir_x, 2));	
	ray->delta_dist_y = sqrt(1 + pow(ray->ray_dir_x, 2) / pow(ray->ray_dir_y, 2));	
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
		ray->side_dist_y = (ray->map_y + 1 - ray->pos_y) * ray->delta_dist_y;
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
	ray->lineheight = (int)(WIN_H / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + WIN_H / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + WIN_H / 2;
	if (ray->drawend >= WIN_H)
		ray->drawend = WIN_H - 1;
	printf("drawstart = %d\n", ray->drawstart);
	printf("drawend = %d\n", ray->drawend);
	printf("len = %f\n", ray->perpwalldist);
}

int main(void)
{
	t_ray	ray;
	ray.drawstart = 0;
	ray.drawend = 10;
	ray.win.mlx = mlx_init();
	ray.win.win = mlx_new_window(ray.win.mlx, WIN_W, WIN_H, "test Raycasting");
	ray.img.img = mlx_new_image(ray.win.mlx, WIN_W, WIN_H);
	ray.img.addr = mlx_get_data_addr(ray.img.img, &ray.img.bpp, &ray.img.line_l, &ray.img.endian);
	mlx_hook(ray.win.win, 2, 1L<<0, move, &ray);
	//algo(&ray);
	mlx_loop(ray.win.mlx);
	return (0);
}
