#include "include.h"
#include "mapo.h"
/*
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

void	init_text(char *path, t_tx *text, void *mlx)
{
	text->img = mlx_xpm_file_to_image(mlx, path, &text->width, &text->height);
	text->addr = mlx_get_data_addr(text->img, &text->bpp, &text->line_l, &text->endian);
}*/

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
		my_put_pixel(&ray->img, x, y, index_color(ray->tex_x, ray->tex_y, txt));
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

void sort_sprite(int sp_order[SP_NUM], double sp_dist[SP_NUM], int num_sp)
{
	int	tmp_o;
	double	tmp_d;
	int	x;
	int	y;
	x = 0;
	y = 1;
	while (x < num_sp - 1)
	{
		while (y < num_sp)
		{
			if (sp_dist[x] < sp_dist[y])
			{
				tmp_d = sp_dist[x];
				tmp_o = sp_order[x];
				sp_dist[x] = sp_dist[y];
				sp_dist[y] = tmp_d;
				sp_order[x] = sp_order[y];
				sp_order[y] = tmp_o;
				x = 0;
				y = x + 1;
			}
			else
				y++;
		}
		x++;
		y = x + 1;
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
	else if (keycode == 65361) //rotate left
	{
		ray->pa -= ray->rot_spd;
		if (ray->pa < 0)
			ray->pa += (2 * M_PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		ray->plan_x = ray->plan_x * cosf(-ray->rot_spd) - ray->plan_y * sinf(-ray->rot_spd);
		ray->plan_y = old_plx * sinf(-ray->rot_spd) + ray->plan_y * cosf(-ray->rot_spd);
	}
	else if (keycode == 65363) //rotate right
	{
		ray->pa += ray->rot_spd;
		if (ray->pa > 2 * M_PI)
			ray->pa -= (2 * M_PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		ray->plan_x = ray->plan_x * cosf(ray->rot_spd) - ray->plan_y * sinf(ray->rot_spd);
		ray->plan_y = old_plx * sinf(ray->rot_spd) + ray->plan_y * cosf(ray->rot_spd);
	}
	else if (keycode == 122) // forward
	{
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * ray->move_spd)] == 0)
			ray->pos_x += ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y + ray->dir_y * ray->move_spd)][(int)(ray->pos_x)] == 0)
			ray->pos_y += ray->dir_y * ray->move_spd;
	}
	else if (keycode == 115) // backward
	{
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x - ray->dir_x * ray->move_spd)] == 0)
			ray->pos_x -= ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y - ray->dir_y * ray->move_spd)][(int)(ray->pos_x)] == 0)
			ray->pos_y -= ray->dir_y * ray->move_spd;
	}
	else if (keycode == 113) //crabe left
	{
		old_pa = ray->pa;
		ray->pa -= (2 * M_PI / 4);
		if (ray->pa < 0)
			ray->pa += (2 * M_PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * ray->move_spd * 2)] == 0)
			ray->pos_x += ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y + ray->dir_y * ray->move_spd * 2)][(int)(ray->pos_x)] == 0)
			ray->pos_y += ray->dir_y * ray->move_spd;
		ray->pa = old_pa;
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
	}
	else if (keycode == 100) //crabe right
	{
		old_pa = ray->pa;
		ray->pa += (2 * M_PI / 4);
		if (ray->pa > 2 * M_PI)
			ray->pa -= (2 * M_PI);
		ray->dir_x = cosf(ray->pa);
		ray->dir_y = sinf(ray->pa);
		if (map[(int)(ray->pos_y)][(int)(ray->pos_x + ray->dir_x * ray->move_spd * 2)] == 0)
			ray->pos_x += ray->dir_x * ray->move_spd;
		if (map[(int)(ray->pos_y + ray->dir_y * ray->move_spd * 2)][(int)(ray->pos_x)] == 0)
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
		ray->zbuffer[x] = ray->perpwalldist;
	}
	for (int i = 0; i < SP_NUM; i++)
	{
		ray->sp_order[i] = i;
		ray->sp_dist[i] = (pow((ray->pos_x - ray->sp[i].pos_x), 2) + pow((ray->pos_y - ray->sp[i].pos_y), 2));
	}
	sort_sprite(ray->sp_order, ray->sp_dist, SP_NUM);
	for (int i = 0; i < SP_NUM; i++)
	{
		// translate sprite pos to relative to camera
		ray->sp_x = ray->sp[ray->sp_order[i]].pos_x - ray->pos_x;
		ray->sp_y = ray->sp[ray->sp_order[i]].pos_y - ray->pos_y;
		// transform sprite with the inverse camera matrix
		ray->invdet = 1.0 / (ray->plan_x * ray->dir_y - ray->dir_x * ray->plan_y);
		ray->transformx = ray->invdet * (ray->dir_y * ray->sp_x - ray->dir_x * ray->sp_y);
		ray->transformy = ray->invdet * (-ray->plan_y * ray->sp_x + ray->plan_x * ray->sp_y);
		ray->sp_screenx = (int)((WIN_W / 2) * (1 + ray->transformx / ray->transformy));
		// calcul height
		ray->sp_height = abs((int)(WIN_H / ray->transformy));
		// calcul lowest and heighest pixel to fill in current stipe
		ray->drawstart_y = -ray->sp_height / 2 + WIN_H / 2;
		if (ray->drawstart_y < 0)
			ray->drawstart_y = 0;
		ray->drawend_y = ray->sp_height / 2 + WIN_H / 2;
		if (ray->sp_height >= WIN_H)
			ray->drawend_y = WIN_H - 1;
		// calcul width of the sprite
		ray->sp_width = abs((int)(WIN_H / ray->transformy));
		ray->drawstart_x = -ray->sp_width / 2 + ray->sp_screenx;
		if (ray->drawstart_x < 0)
			ray->drawstart_x = 0;
		ray->drawend_x = ray->sp_width / 2 + ray->sp_screenx;
		if (ray->drawend_x >= WIN_W)
			ray->drawend_x = WIN_W - 1;
		for (int stripe = ray->drawstart_x; stripe < ray->drawend_x; stripe++)
		{
			ray->tex_x = (int)(256 * (stripe - (-ray->sp_width / 2 + ray->sp_screenx)) * ray->txt[4].width / ray->sp_width) / 256;
			if (ray->transformy > 0 && stripe > 0 && stripe < WIN_W && ray->transformy < ray->zbuffer[stripe])
			{
				for (int y = ray->drawstart_y; y < ray->drawend_y; y++)
				{
					int d = (y) * 256 - WIN_H * 128 + ray->sp_height * 128;
					ray->tex_y = ((d * ray->txt[4].height) / ray->sp_height) / 256;
					int color = index_color(ray->tex_x, ray->tex_y, &ray->txt[4]);
					if (color != 0)
					my_put_pixel(&ray->img, stripe, y, color);
				}
			}
		}
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
		init_text(av[i+1], &ray.txt[i], ray.win.mlx);
	}
	//printf("color = %d\n", index_color(0, 0, &ray.txt[4]));
	ray.sp[0].pos_x = 5.5;
	ray.sp[0].pos_y = 1.5;
	ray.sp[1].pos_x = 5.5;
	ray.sp[1].pos_y = 3.5;
	ray.drawstart = 0;
	ray.drawend = 10;
	ray.pa = M_PI;
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
