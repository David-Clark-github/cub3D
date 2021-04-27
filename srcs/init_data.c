/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:55:14 by dclark            #+#    #+#             */
/*   Updated: 2021/04/27 13:23:58 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_data(t_data *data)
{
	data->raw_cub = NULL;
	data->nb_l = 0;
	init_id_l(&data->id_l);
	init_win(&data->win);
	init_img(&data->img);
	init_map(&data->map);
	init_ply(&data->ply);
	init_ray(&data->ray);
	init_text(data);
	data->sp = NULL;
}
