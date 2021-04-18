/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:55:14 by dclark            #+#    #+#             */
/*   Updated: 2021/04/18 13:08:55 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_data(t_data *data)
{
	data->raw_cub = NULL;
	init_id_l(&data->id_l);
	init_win(&data->win);
	init_img(&data->img);
	init_map(&data->map);
	init_ply(&data->ply);
	init_ray(&data->ray);
	init_text(data);
	data->d_map = -1;
	data->sp = NULL;
}
