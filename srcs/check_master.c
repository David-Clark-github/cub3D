/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:55:18 by dclark            #+#    #+#             */
/*   Updated: 2021/04/27 15:46:24 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	check_master(t_data *data)
{
	check_res(data->raw_cub[data->id_l.res], data);
	check_xpm(data->raw_cub[data->id_l.north], data);
	check_xpm(data->raw_cub[data->id_l.south], data);
	check_xpm(data->raw_cub[data->id_l.east], data);
	check_xpm(data->raw_cub[data->id_l.west], data);
	check_xpm(data->raw_cub[data->id_l.sprite], data);
	check_floor_ceil(data->raw_cub[data->id_l.floor], data);
	check_floor_ceil(data->raw_cub[data->id_l.ceil], data);
	check_map1(&data->raw_cub[data->id_l.map], data);
	check_map2(&data->raw_cub[data->id_l.map], data);
}
