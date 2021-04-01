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

void	init_tx(char *path, t_tx *text, void *mlx)
{
	text->img = mlx_xpm_file_to_image(mlx, path, &text->width, &text->height);
	text->addr = mlx_get_data_addr(text->img, &text->bpp, &text->line_l, &text->endian);
//	printf("text->img = %p\n", text->img);
//	printf("text->height = %d\n", text->height);
//	printf("text->width = %d\n", text->width);
}

int	index_color(int x, int y, t_tx *txt)
{
	int	index = (y * txt->line_l + x * (txt->bpp / 8));
	return (((int *)txt->addr)[index/4]);
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


void	draw_txt_line(t_tx *txt, int x, t_ray *ray)
{
	int		y;

	ray->step = 1.0 * txt->height / ray->lineheight;
	ray->tex_pos = (ray->drawstart - WIN_H / 2 + ray->lineheight / 2) * ray->step;
	y = ray->drawstart - 1;
	while (++y < ray->drawend)
	{
		ray->tex_y = (int)ray->tex_pos;
		ray->tex_pos += ray->step;
		my_put_pixel(&ray->img, x, y, index_color(ray->tex_x, (int)ray->tex_y, txt));
	}
}

void	draw_vertical_line(t_img *img, int x, int start, int end, int color)
{
	while (start < end)
	{
		++start;
		my_put_pixel(img, x, start, color);
	}
}

int		move(int keycode, void *param)
{
	t_ray	*ray;

	ray = param;
	double	old_dir_x = ray->dir_x;
	double	old_plx = ray->plan_x;
	double	old_pa;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	else if (keycode == 65361) //turn left
	{
//		ray->dir_x = ray->dir_x * cosf(-ray->rot_spd) - ray->dir_y * sinf(-ray->rot_spd);
//		ray->dir_y = old_dir_x * sinf(-ray->rot_spd) + ray->dir_y * cosf(-ray->rot_spd);
		ray->pa -= ray->rot_spd;
		if (ray->pa < 0)
			ray->pa += (2 * PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		ray->plan_x = ray->plan_x * cosf(-ray->rot_spd) - ray->plan_y * sinf(-ray->rot_spd);
		ray->plan_y = old_plx * sinf(-ray->rot_spd) + ray->plan_y * cosf(-ray->rot_spd);
	}
	else if (keycode == 65363) //turn right
	{
//		ray->dir_x = ray->dir_x * cosf(ray->rot_spd) - ray->dir_y * sinf(ray->rot_spd);
//		ray->dir_y = old_dir_x * sinf(ray->rot_spd) + ray->dir_y * cosf(ray->rot_spd);
		ray->pa += ray->rot_spd;
		if (ray->pa > 2 * PI)
			ray->pa -= (2 * PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		ray->plan_x = ray->plan_x * cosf(ray->rot_spd) - ray->plan_y * sinf(ray->rot_spd);
		ray->plan_y = old_plx * sinf(ray->rot_spd) + ray->plan_y * cosf(ray->rot_spd);
	}
	else if (keycode == 122) // forward
	{
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * ray->move_spd)] != 1)
			ray->pos_x += ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y + ray->dir_y * ray->move_spd)][(int)(ray->pos_x)] != 1)
			ray->pos_y += ray->dir_y * ray->move_spd;
	}
	else if (keycode == 115) // backward
	{
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x - ray->dir_x * ray->move_spd)] != 1)
			ray->pos_x -= ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y - ray->dir_y * ray->move_spd)][(int)(ray->pos_x)] != 1)
			ray->pos_y -= ray->dir_y * ray->move_spd;
	}
	else if (keycode == 113) //crabe left
	{
		old_pa = ray->pa;
		ray->pa -= (2 * PI / 4);
		if (ray->pa < 0)
			ray->pa += (2 * PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * ray->move_spd * 2)] != 1)
			ray->pos_x += ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y + ray->dir_y * ray->move_spd * 2)][(int)(ray->pos_x)] != 1)
			ray->pos_y += ray->dir_y * ray->move_spd;
		ray->pa = old_pa;
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
	}
	else if (keycode == 100) //crabe right
	{
		old_pa = ray->pa;
		ray->pa += (2 * PI / 4);
		if (ray->pa > 2 * PI)
			ray->pa -= (2 * PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * ray->move_spd * 2)] != 1)
			ray->pos_x += ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y + ray->dir_y * ray->move_spd * 2)][(int)(ray->pos_x)] != 1)
			ray->pos_y += ray->dir_y * ray->move_spd;
		ray->pa = old_pa;
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
	}
	algo(ray);
	return (1);
}

void	algo(t_ray *ray)
{

	int x = -1;
	init_image(&ray->img, WIN_W, WIN_H, trgb(FLOOR), trgb(CEIL));
	while (++x < WIN_W)
	{
		ray->hit = 0;
		ray->camera_x = 2 * x / (double)WIN_W - 1;
		ray->ray_dir_x = ray->dir_x + ray->plan_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plan_y * ray->camera_x;
		ray->map_x = (int)ray->pos_x;
		ray->map_y = (int)ray->pos_y;
		ray->delta_dist_x = sqrt(1 + pow(ray->ray_dir_y, 2) / pow(ray->ray_dir_x, 2));	
		ray->delta_dist_y = sqrt(1 + pow(ray->ray_dir_x, 2) / pow(ray->ray_dir_y, 2));	
		if (ray->ray_dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
		}
		if (ray->ray_dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
		}
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
		if (ray->side == 0)
			ray->perpwalldist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
		else
			ray->perpwalldist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
		ray->lineheight = (int)(WIN_H / ray->perpwalldist);
		ray->drawstart = (-ray->lineheight + WIN_H) / 2;
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		ray->drawend = (ray->lineheight + WIN_H) / 2;
		if (ray->drawend >= WIN_H)
			ray->drawend = WIN_H - 1;
		/*
		** Calcul des coordonnees pour la texture
		** cast en int (wallx) pour l'utiliser en map :)
		*/
		if (ray->side == 0)
			ray->wall_x = ray->pos_y + ray->perpwalldist * ray->ray_dir_y;
		else
			ray->wall_x = ray->pos_x + ray->perpwalldist * ray->ray_dir_x;
		ray->wall_x -= floor(ray->wall_x);
		ray->tex_x = (int)(ray->wall_x * TXT_W);
		/*
		** Colorier les murs en fonctions de leurs directions
		*/
		if (ray->ray_dir_x > 0 && ray->side == 0)
			draw_txt_line(&ray->txt[0], x, ray);
		else if (ray->ray_dir_x < 0 && ray->side == 0)
			draw_txt_line(&ray->txt[1], x, ray);
		else if (ray->ray_dir_y > 0 && ray->side != 0)
			draw_txt_line(&ray->txt[2], x, ray);
		else if (ray->ray_dir_y < 0 && ray->side != 0)
			draw_txt_line(&ray->txt[3], x, ray);
	}
	mlx_put_image_to_window(ray->win.mlx, ray->win.win, ray->img.img, 0, 0);
	mlx_loop(ray->win.mlx);
}

int main(int ac, char **av)
{
	t_ray	ray;
	ray.win.mlx = mlx_init();
	ray.win.win = mlx_new_window(ray.win.mlx, WIN_W, WIN_H, "test Raycasting");
	for (int i = 0; i < 5; i++)
	{
		init_tx(av[i+1], &ray.txt[i], ray.win.mlx);
	}
	ray.drawstart = 0;
	ray.drawend = 10;
	ray.pa = PI;
	ray.dir_x = cosf(ray.pa);//-1.0;
	ray.dir_y = sinf(ray.pa);//0.0;
	ray.pos_x = 3.5;
	ray.pos_y = 4.5;
	ray.plan_x = 0.0;
	ray.plan_y = -0.66;
	ray.time = 0.0;
	ray.rot_spd = 0.05;
	ray.move_spd = 0.1;
	ray.img.img = mlx_new_image(ray.win.mlx, WIN_W, WIN_H);
	ray.img.addr = mlx_get_data_addr(ray.img.img, &ray.img.bpp, &ray.img.line_l, &ray.img.endian);
	mlx_hook(ray.win.win, 2, 1L<<0, move, &ray);
	mlx_loop(ray.win.mlx);
	return (0);
}
