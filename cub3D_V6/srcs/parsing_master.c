/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:35:44 by dclark            #+#    #+#             */
/*   Updated: 2021/04/09 16:06:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	parsing_master(t_data *data)
{
	pars_res(data, data->raw_cub[data->id_l.res]);
	pars_xpm(data, 0, data->raw_cub[data->id_l.north]);
	pars_xpm(data, 1, data->raw_cub[data->id_l.south]);
	pars_xpm(data, 2, data->raw_cub[data->id_l.east]);
	pars_xpm(data, 3, data->raw_cub[data->id_l.west]);
	pars_xpm(data, 4, data->raw_cub[data->id_l.sprite]);
	pars_sprite(data->map.map, data);
	pars_floor(data, data->raw_cub[data->id_l.floor]);
	pars_ceil(data, data->raw_cub[data->id_l.ceil]);
	pars_ply(data->map.map, data);
	pars_img(&data->img, &data->win);
	print_data(data);
}
