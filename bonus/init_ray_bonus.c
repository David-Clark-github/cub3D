/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:15:51 by dclark            #+#    #+#             */
/*   Updated: 2021/04/10 12:12:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_1(t_ray *ray)
{
	ray->rdirx = 0;
	ray->rdiry = 0;
	ray->camerax = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->time = 0;
	ray->old_time = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perpwd = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->wallx = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->tex_pos = 0;
	ray->step = 0;
	ray->x = 0;
}

void	init_2(t_ray *ray)
{
	ray->zbuffer = NULL;
	ray->sp_order = NULL;
	ray->sp_dist = NULL;
	ray->sp_x = 0;
	ray->sp_y = 0;
	ray->invdet = 0;
	ray->transformx = 0;
	ray->transformy = 0;
	ray->sp_screenx = 0;
	ray->sp_height = 0;
	ray->sp_width = 0;
	ray->drawst_x = 0;
	ray->drawst_y = 0;
	ray->drawend_x = 0;
	ray->drawend_y = 0;
}

void	init_ray(t_ray *ray)
{
	init_1(ray);
	init_2(ray);
}
