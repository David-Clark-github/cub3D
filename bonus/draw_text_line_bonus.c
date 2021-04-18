/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:44:52 by dclark            #+#    #+#             */
/*   Updated: 2021/04/18 11:44:23 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	color_shadow(int color_init, double perpwd)
{
	int	r;
	int	g;
	int	b;
	
	if (perpwd > 4)
	{
		r = (color_init >> 16) & (int)(pow(-perpwd, 2));
		g = (color_init >> 8) & (int)(pow(-perpwd, 2));
		b = (color_init) & (int)(pow(-perpwd, 2));
		if (trgb(0, r, g, b) < color_init)
			return (trgb(0, r, g, b));
		else
			return (color_init);
	}
	return (color_init);
}

void	draw_text_line(t_text *text, int x, t_ray *ray, t_data *data)
{
	int	y;
	int	new_color;

	ray->step = 1.0 * text->height / ray->lineheight;
	ray->tex_pos = (ray->drawstart - data->win.height / 2 +\
	ray->lineheight / 2) * ray->step;
	y = ray->drawstart - 1;
	while (++y < ray->drawend)
	{
		ray->tex_y = (int)ray->tex_pos;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		ray->tex_pos += ray->step;
		new_color = color_shadow(index_color(ray->tex_x, ray->tex_y, text), data->ray.perpwd);
		(void)new_color;
		my_put_pixel(&data->img, x, y, index_color(ray->tex_x,\
		ray->tex_y, text));
	}
}
