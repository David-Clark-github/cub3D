/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:02:29 by dclark            #+#    #+#             */
/*   Updated: 2021/04/12 14:27:30 by dclark           ###   ########.fr       */
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
		while (map[y][++x])
			if (map[y][x] == '2')
				mapou->sp_num++;
	}
}

void		sprite_pos(char **map, t_data *data)
{
	int	i;
	int	y;
	int	x;

	y = -1;
	i = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
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

void		pars_sprite(char **map, t_data *data)
{
	pars_sp_num(map, &data->map);
	if (!(data->sp = malloc(sizeof(t_sp) * data->map.sp_num)))
		ft_error("le malloc sprite a échoué", 1, data);
	if (!(data->ray.zbuffer = malloc(sizeof(double) * data->win.width)))
		ft_error("le malloc de zbuffer a échoué", 1, data);
	if (!(data->ray.sp_order = malloc(sizeof(int) * data->map.sp_num)))
		ft_error("le malloc de sp_order a échoué", 1, data);
	if (!(data->ray.sp_dist = malloc(sizeof(double) * data->map.sp_num)))
		ft_error("le malloc de sp_dist a échoué", 1, data);
	sprite_pos(map, data);
}
