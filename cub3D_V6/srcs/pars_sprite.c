/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:02:29 by dclark            #+#    #+#             */
/*   Updated: 2021/04/09 11:36:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	pars_sp_num(char **map, t_mapou *mapou)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while(map[y][++x])
			if (map[y][x] == '2')
				mapou->sp_num++;
	}
}

void	pars_sprite(char **map, t_data *data)
{
	int	i;
	int	y;
	int	x;

	y = -1;
	i = 0;
	pars_sp_num(map, &data->map);
	if (!(data->sp = malloc(sizeof(t_sp) * data->map.sp_num)))
		ft_error("malloc sprite echoué", 1, data);
	while (map[++y])
	{
		x = -1;
		while(map[y][++x])
		{
			if (map[y][x] == '2')
			{
				data->sp[i].posx = x + 0.5;
				data->sp[i].posy = y + 0.5;
				++i;
			}
		}
	}
}
