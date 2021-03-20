/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:07:05 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 11:20:35 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	draw_square(t_img_a *img_a, int x, int y, int size, int color)
{
	int y_s;
	int	x_s;

	y_s = 0;
	x_s = 0;
	while (y_s < size)
	{
		while (x_s < size)
		{
			my_put_pixel(img_a, (x + x_s), (y + y_s), color);
			x_s++;
		}
		x_s = 0;
		y_s++;
	}
}
