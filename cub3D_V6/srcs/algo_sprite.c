/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 15:56:57 by dclark            #+#    #+#             */
/*   Updated: 2021/04/11 16:52:42 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	sort_sprite(int	*sp_order, double *sp_dist, int sp_num)
{
	int		tmp_o;
	double	tmp_d;
	int		x;
	int		y;

	x = 0;
	y = 1;
	while (x < data->map.sp_num - 1)
	{
		while (y < data->map.sp_num)
		{
			if (sp_dist[x] < sp_dist[y])
			{
				tmp_d = sp_dist[x];
				tmp_o = sp_order[x];
				sp_dist[x] = sp_dist[y];
				sp_dist[y] = tmp_d;
				sp_order[x] = sp_order[y];
				sp_order[y] = tmp_o;
				x = 0
				y = x + 1;
			}
			else
				++y;
		}
		++x;
		y = x + 1;
	}
}

void	algo_sprite(t_data *data, t_ray *ray, t_ply *ply, t_sp *sp)
{
	int	i;

	i = 0;
	while (i < data->map.sp_num)
	{
		ray->sp_order[i] = i;
		ray->sp_dist[i] = pow(ply->posx - sp[i]->posx, 2) +\
		pow(ply->posy - sp[i]->posy, 2);
		++i;
	}
	sort_sprite(ray->sp_order, ray->sp_dist, data->map.sp_num);
}
