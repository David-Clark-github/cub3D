/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_line_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 14:22:16 by dclark            #+#    #+#             */
/*   Updated: 2021/04/27 15:59:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	id_line_master(t_data *data)
{
	data->id_l.res = id_res(data->raw_cub, data);
	data->id_l.north = id_north(data->raw_cub, data);
	data->id_l.south = id_south(data->raw_cub, data);
	data->id_l.east = id_east(data->raw_cub, data);
	data->id_l.west = id_west(data->raw_cub, data);
	data->id_l.sprite = id_sprite(data->raw_cub, data);
	data->id_l.floor = id_floor(data->raw_cub, data);
	data->id_l.ceil = id_ceil(data->raw_cub, data);
	data->id_l.map = id_map(data->raw_cub, data);
}
