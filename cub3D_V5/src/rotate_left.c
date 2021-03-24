/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:26:22 by dclark            #+#    #+#             */
/*   Updated: 2021/03/21 13:27:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	rotate_left(t_data *data)
{
	data->player.pa -= 0.1;
	if (data->player.pa < 0)
		data->player.pa += 2 * PI;
	data->player.pdx = cosf(data->player.pa) * 5;
	data->player.pdy = sinf(data->player.pa) * 5;
}