/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:56:57 by dclark            #+#    #+#             */
/*   Updated: 2021/04/18 15:52:14 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	sort_sprite(int *sp_order, double *sp_dist, int sp_num)
{
	int		tmp_o;
	double	tmp_d;
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (++x < sp_num - 1)
	{
		while (++y < sp_num)
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
		}
		y = x + 1;
	}
}

static void	algo_sp1(t_ray *ray, t_ply *ply, t_data *data, int i)
{
	ray->sp_x = data->sp[ray->sp_order[i]].posx - data->ply.posx;
	ray->sp_y = data->sp[ray->sp_order[i]].posy - data->ply.posy;
	ray->invdet = 1.0 / (ply->planx * ply->diry - ply->dirx * ply->plany);
	ray->transformx = ray->invdet * (ply->diry * ray->sp_x - ply->dirx *\
	ray->sp_y);
	ray->transformy = ray->invdet * (-ply->plany * ray->sp_x + ply->planx *\
	ray->sp_y);
	ray->sp_screenx = (int)((data->win.width / 2) *\
	(1 + ray->transformx / ray->transformy));
	ray->sp_height = abs((int)(data->win.height / ray->transformy));
	ray->drawst_y = (-ray->sp_height + data->win.height) / 2;
	if (ray->drawst_y < 0)
		ray->drawst_y = 0;
	ray->drawend_y = (ray->sp_height + data->win.height) / 2;
	if (ray->sp_height >= data->win.height)
		ray->drawend_y = data->win.height - 1;
	ray->sp_width = abs((int)(data->win.height / ray->transformy));
	ray->drawst_x = -ray->sp_width / 2 + ray->sp_screenx;
	if (ray->drawst_x < 0)
		ray->drawst_x = 0;
	ray->drawend_x = ray->sp_width / 2 + ray->sp_screenx;
	if (ray->drawend_x >= data->win.width)
		ray->drawend_x = data->win.width - 1;
}

static void	algo_sp2(t_data *data, t_ray *ray)
{
	int	stripe;
	int	y;
	int	d;
	int	color;

	stripe = ray->drawst_x - 1;
	while (++stripe < ray->drawend_x)
	{
		ray->tex_x = (int)((stripe - (-ray->sp_width / 2 +\
		ray->sp_screenx)) * data->text[4].width / ray->sp_width);
		if (ray->transformy > 0 && stripe > 0 && stripe < data->win.width\
			&& ray->transformy < ray->zbuffer[stripe])
		{
			y = ray->drawst_y - 1;
			while (++y < ray->drawend_y)
			{
				d = (y) - data->win.height / 2 + ray->sp_height / 2;
				ray->tex_y = ((d * data->text[4].height) / ray->sp_height);
				color = index_color(ray->tex_x, ray->tex_y, &data->text[4]);
				if (color != 0)
					my_put_pixel(&data->img, stripe, y, color);
			}
		}
	}
}

void		algo_sprite(t_data *data, t_ray *ray, t_ply *ply)
{
	int	i;

	i = 0;
	while (i < data->map.sp_num)
	{
		ray->sp_order[i] = i;
		ray->sp_dist[i] = pow(ply->posx - data->sp[i].posx, 2) +\
		pow(ply->posy - data->sp[i].posy, 2);
		++i;
	}
	sort_sprite(ray->sp_order, ray->sp_dist, data->map.sp_num);
	i = -1;
	while (++i < data->map.sp_num)
	{
		algo_sp1(ray, ply, data, i);
		algo_sp2(data, ray);
	}
}
