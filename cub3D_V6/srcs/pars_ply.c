/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:54:35 by dclark            #+#    #+#             */
/*   Updated: 2021/04/10 10:41:51 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	ply_dir(char c, t_ply *ply)
{
	if (c == 'N')
	{
		ply->pa = M_PI / 2;
		ply->planx = -0.66;
		ply->plany = 0.0;
	}
	if (c == 'S')
	{
		ply->pa = 3 * M_PI / 2;
		ply->planx = 0.66;
		ply->plany = 0.0;
	}
	if (c == 'E')
	{
		ply->pa = 2 * M_PI;
		ply->planx = 0.0;
		ply->plany = 0.66;
	}
	if (c == 'W')
	{
		ply->pa = M_PI;
		ply->planx = 0.0;
		ply->plany = -0.66;
	}
}

void		pars_ply(char **map, t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_isalpha(map[y][x]))
			{
				data->ply.posx = x + 0.5;
				data->ply.posy = y + 0.5;
				ply_dir(map[y][x], &data->ply);
				map[y][x] = '0';
				break ;
			}
		}
	}
	data->ply.rot_spd = 0.05;
	data->ply.mv_spd = 0.08;
	data->ply.dirx = cosf(data->ply.pa);
	data->ply.diry = sinf(data->ply.pa);
}
