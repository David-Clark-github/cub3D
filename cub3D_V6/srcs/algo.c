/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:28:44 by dclark            #+#    #+#             */
/*   Updated: 2021/04/14 11:09:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	init_algo1(t_ray *ray, t_data *data)
{
	ray->hit = 0;
	ray->camerax = 2 * ray->x / (double)data->win.width - 1;
	ray->rdirx = data->ply.dirx + data->ply.planx * ray->camerax;
	ray->rdiry = data->ply.diry + data->ply.plany * ray->camerax;
	ray->mapx = (int)data->ply.posx;
	ray->mapy = (int)data->ply.posy;
	ray->deltadistx = sqrt(1 + pow(ray->rdiry, 2) / pow(ray->rdirx, 2));
	ray->deltadisty = sqrt(1 + pow(ray->rdirx, 2) / pow(ray->rdiry, 2));
}

static void	init_algo2(t_ray *ray, t_ply *ply)
{
	if (ray->rdirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ply->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ply->posx) * ray->deltadistx;
	}
	if (ray->rdiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ply->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ply->posy) * ray->deltadisty;
	}
}

static void	init_algo3(t_ray *ray, t_ply *ply, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (data->map.map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwd = (ray->mapx - ply->posx + (1 - ray->stepx) / 2) \
		/ ray->rdirx;
	else
		ray->perpwd = (ray->mapy - ply->posy + (1 - ray->stepy) / 2) \
		/ ray->rdiry;
}

static void	init_algo4(t_win *win, t_ray *ray, t_ply *ply)
{
	ray->lineheight = (int)(win->height / ray->perpwd);
	ray->drawstart = (-ray->lineheight + win->height) / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (ray->lineheight + win->height) / 2;
	if (ray->drawend >= win->height)
		ray->drawend = win->height - 1;
	if (ray->side == 0)
		ray->wallx = ply->posy + ray->perpwd * ray->rdiry;
	else
		ray->wallx = ply->posx + ray->perpwd * ray->rdirx;
	ray->wallx -= floor(ray->wallx);
	ray->tex_x = (int)(ray->wallx * 64);
}

void		algo(t_data *data)
{
	data->ray.x = -1;
	while (++data->ray.x < data->win.width)
	{
		init_algo1(&data->ray, data);
		init_algo2(&data->ray, &data->ply);
		init_algo3(&data->ray, &data->ply, data);
		init_algo4(&data->win, &data->ray, &data->ply);
		if (data->ray.rdirx > 0 && data->ray.side == 0)
			draw_text_line(&data->text[2], data->ray.x, &data->ray, data);
		else if (data->ray.rdirx < 0 && data->ray.side == 0)
			draw_text_line(&data->text[3], data->ray.x, &data->ray, data);
		else if (data->ray.rdiry > 0 && data->ray.side != 0)
			draw_text_line(&data->text[1], data->ray.x, &data->ray, data);
		else if (data->ray.rdiry < 0 && data->ray.side != 0)
			draw_text_line(&data->text[0], data->ray.x, &data->ray, data);
		data->ray.zbuffer[data->ray.x] = data->ray.perpwd;
	}
	algo_sprite(data, &data->ray, &data->ply);
}
