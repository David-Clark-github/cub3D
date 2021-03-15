/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:38:56 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 13:12:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	draw_square(t_map_img *map_img, int x, int y, int size, int color)
{
	int y_s;
	int	x_s;

	y_s = 0;
	x_s = 0;
	while (y_s < size)
	{
		while (x_s < size)
		{
			my_mlx_pixel(map_img, (x + x_s), (y + y_s), color);
			x_s++;
		}
		x_s = 0;
		y_s++;
	}
}

