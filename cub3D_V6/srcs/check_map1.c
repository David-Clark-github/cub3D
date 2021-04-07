/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:42:49 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 14:58:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	map_limits(t_data *data, char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) > data->map.map_w)
			data->map.map_w = ft_strlen(map[y]);
		y++;
	}
	data->map.map_h = y;
}

void	check_empty_l(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		if (ft_strlen(map[y]) == 0)
			ft_error("Il y a une ligne vide dans la map", 1, 0);
}

static void	check_cara(char **map)
{
	int	y;
	int	x;

	y = -1;
	while(map[++y])
	{
		x = -1;
		while(map[y][++x])
		{
			if (ft_strrchr(" 012NSEW", map[y][x]) == 0)
				ft_error("Mauvais caractere dans la map", 1, 0);
		}
	}
}

static void	check_player(char **map)
{
	int	y;
	int	x;
	int	res;

	y = -1;
	res = 0;
	while(map[++y])
	{
		x = -1;
		while(map[y][++x])
		{
			if (ft_strrchr("NSEW", map[y][x]) != 0)
				res++;
		}
	}
	if (res > 1)
		ft_error("Il y a trop de joueur dans la map", 1, 0);
	if (res == 0)
		ft_error("Il y n'a pas joueur dans la map", 1, 0);
}

void		check_map1(char **map, t_data *data)
{
	map_limits(data, map);
	check_empty_l(map);
	check_cara(map);
	check_player(map);
}
