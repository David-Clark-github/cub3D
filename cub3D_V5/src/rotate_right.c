/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:29:36 by dclark            #+#    #+#             */
/*   Updated: 2021/03/25 10:43:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	rotate_right(t_data *data)
{
	data->player.pa += 0.1;
	if (data->player.pa > 2 * PI)
		data->player.pa -= 2 * PI;
	data->player.pdx = cosf(data->player.pa) * 1;
	data->player.pdy = sinf(data->player.pa) * 1;
//	printf("\nrot pdx = %f\n", data->player.pdx);
//	printf("rot pdy = %f\n", data->player.pdy);
}
