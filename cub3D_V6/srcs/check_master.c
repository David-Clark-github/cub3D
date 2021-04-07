/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:55:18 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 14:59:02 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	check_master(t_data *data)
{
	check_res(data->raw_cub[data->id_l.res]);
	check_xpm(data->raw_cub[data->id_l.north]);
	check_xpm(data->raw_cub[data->id_l.south]);
	check_xpm(data->raw_cub[data->id_l.east]);
	check_xpm(data->raw_cub[data->id_l.west]);
	check_xpm(data->raw_cub[data->id_l.sprite]);
	check_floor_ceil(data->raw_cub[data->id_l.floor]);
	check_floor_ceil(data->raw_cub[data->id_l.ceil]);
	check_map1(&data->raw_cub[data->id_l.map], data);
}
