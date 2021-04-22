/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:44:52 by dclark            #+#    #+#             */
/*   Updated: 2021/04/22 10:19:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	draw_text_line(t_text *text, int x, t_ray *ray, t_data *data)
{
	int	y;

	ray->step = 1.0 * text->height / ray->lineheight;
	ray->tex_pos = (ray->drawstart - data->win.height / 2 +\
	ray->lineheight / 2) * ray->step;
	y = ray->drawstart - 1;
	while (++y <= ray->drawend)
	{
		ray->tex_y = (int)ray->tex_pos;
		if (ray->tex_y < 0)
			ray->tex_y = 0;
		ray->tex_pos += ray->step;
		my_put_pixel(&data->img, x, y, index_color(ray->tex_x,\
		ray->tex_y, text));
	}
}
