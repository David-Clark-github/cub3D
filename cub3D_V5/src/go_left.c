/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:48:42 by dclark            #+#    #+#             */
/*   Updated: 2021/03/21 13:50:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	go_left(t_data *data)
{
	double old_pa;

	old_pa = data->player.pa;
	data->player.pa -= (2 * PI / 4);
	if (data->player.pa < 0)
		data->player.pa += (2 * PI);
	data->player.pdx = cosf(data->player.pa) * 5;
	data->player.pdy = sinf(data->player.pa) * 5;
	data->player.pos_x += data->player.pdx;
	data->player.pos_y += data->player.pdy;
	data->player.pa = old_pa;
	data->player.pdx = cosf(data->player.pa) * 5;
	data->player.pdy = sinf(data->player.pa) * 5;
}
