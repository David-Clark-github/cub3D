/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_texture_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:51:55 by dclark            #+#    #+#             */
/*   Updated: 2021/04/20 14:52:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	while1(t_f_c *f_c, t_data *data)
{
	f_c->raydirx0 = data->ply.dirx - data->ply.planx;
	f_c->raydiry0 = data->ply.diry - data->ply.plany;
	f_c->raydirx1 = data->ply.dirx + data->ply.planx;
	f_c->raydiry1 = data->ply.diry + data->ply.plany;
	f_c->p = f_c->y - data->win.height / 2;
	f_c->posz = 0.5 * data->win.height;
	f_c->rowdist = f_c->posz / f_c->p;
	f_c->floorstepx = f_c->rowdist * (f_c->raydirx1 - f_c->raydirx0)\
	/ data->win.width;
	f_c->floorstepy = f_c->rowdist * (f_c->raydiry1 - f_c->raydiry0)\
	/ data->win.width;
	f_c->floorx = data->ply.posx + f_c->rowdist * f_c->raydirx0;
	f_c->floory = data->ply.posy + f_c->rowdist * f_c->raydiry0;
	f_c->x = -1;
}

void		floor_ceil_texture(t_f_c *f_c, t_data *data)
{
	int	color;

	f_c->y = -1;
	while (++f_c->y < data->win.height)
	{
		while1(f_c, data);
		while (++f_c->x < data->win.width)
		{
			f_c->cellx = (int)(f_c->floorx);
			f_c->celly = (int)(f_c->floory);
			f_c->tx = (int)(64 * (f_c->floorx - f_c->cellx)) & (64 - 1);
			f_c->ty = (int)(64 * (f_c->floory - f_c->celly)) & (64 - 1);
			f_c->floorx += f_c->floorstepx;
			f_c->floory += f_c->floorstepy;
			color = index_color(f_c->tx, f_c->ty, &data->text[2]);
			color = (color >> 1) & 8355711;
			my_put_pixel(&data->img, f_c->x, f_c->y, color);
			color = index_color(f_c->tx, f_c->ty, &data->text[1]);
			color = (color >> 1) & 8355711;
			my_put_pixel(&data->img, f_c->x, (data->win.height - f_c->y - 1)\
			, color);
		}
	}
}
