/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor_to_img_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:47:27 by dclark            #+#    #+#             */
/*   Updated: 2021/04/21 15:41:17 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ceil_floor_to_img(t_data *data)
{
	int	middle;
	int	y;
	int	x;

	middle = data->win.height / 2;
	y = 0;
	while (y < middle)
	{
		x = -1;
		while (++x < data->win.width)
			my_put_pixel(&data->img, x, y, data->ceil.color);
		++y;
	}
	while (y < data->win.height)
	{
		x = -1;
		while (++x < data->win.width)
			my_put_pixel(&data->img, x, y, data->floor.color);
		++y;
	}
}
