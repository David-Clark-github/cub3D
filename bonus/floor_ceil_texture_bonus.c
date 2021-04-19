/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_texture_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:10:15 by dclark            #+#    #+#             */
/*   Updated: 2021/04/19 15:58:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	floor_ceil_texture(t_f_c *f_c, t_data *data)
{
	f_c->y = -1;
	while (++f_c->y < data->win.height)
	{
		f_c->raydirx0 = data->ply.dirx - data->ply.planx;
		f_c->raydiry0 = data->ply.diry - data->ply.plany;
		f_c->raydirx1 = data->ply.dirx + data->ply.planx;
		f_c->raydiry1 = data->ply.diry + data->ply.plany;
		f_c->p = f_c->y - data->win.height / 2;
		f_c->posz = 0.5 * data->win.height;
		f_c->rowdist = f_c->posz / f_c->p;
		f_c->floorstepx = f_c->rowdist * (f_c->dirx1 - f_c->dirx0) / data->win.width;
		f_c->floorstepy = f_c->rowdist * (f_c->diry1 - f_c->diry0) / data->win.width;
		f_c->floorx = data->ply.posx + f_c->rowdist * f_c->raydirx0;
		f_c->floory = data->ply.posy + f_c->rowdist * f_c->raydiry0;
		f_c->x = -1;
		while (++f_c->x < data->win.width)
		{
			f_c->cellx = (int)(f_c->floorx);
			f_c->celly = (int)(f_c->floory);
			f_c->tx = (int)(64 * (f_c->floorx - f_c->cellx)) & (data->win.width - 1);
			f_c->ty = (int)(64 * (f_c->floory - f_c->celly)) & (data->win.height - 1);
			f_c->floorx += f_c->floorstepx;
			f_c->floorx += f_c->floorstepx;
		}
	}
}
