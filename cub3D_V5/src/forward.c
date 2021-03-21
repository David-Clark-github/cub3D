/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:38:45 by dclark            #+#    #+#             */
/*   Updated: 2021/03/21 13:40:22 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	forward(t_data *data)
{
		data->player.pos_x += data->player.pdx;
		data->player.pos_y += data->player.pdy;
}
