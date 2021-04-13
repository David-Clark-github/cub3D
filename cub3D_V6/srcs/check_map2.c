/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:00:42 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 13:29:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	malloc_map(t_data *data)
{
	int	y;

	y = -1;
	if(!(data->map.map = malloc(sizeof(char *) * (data->map.map_h + 1))))
		ft_error("La map n'as pas pu etre cree", 1, data);
	while (++y < data->map.map_h)
	{
		if(!(data->map.map[y] = malloc(sizeof(char) * (data->map.map_w + 1))))
			ft_error("La map n'as pas pu etre cree", 1, data);
	}
}

static void	create_map(char **map, t_data *data)
{
	int	y;
	int	x;
	int	reste;

	y = -1;
	while (++y < data->map.map_h)
	{
		x = 0;
		reste = data->map.map_w - ft_strlen(map[y]);
		while (x < ft_strlen(map[y]))
		{
			data->map.map[y][x] = map[y][x];
			++x;
		}
		while (reste-- > 0)
		{
			data->map.map[y][x] = ' ';
			++x;
		}
		data->map.map[y][x] = '\0';
	}
	data->map.map[y] = 0;
}

static void	voisin(t_data *data, int x, int y)
{
	if (x == 0 || x == data->map.map_w - 1)
		ft_error("map incorrect", 1, data);
	if (y == 0 || y == data->map.map_h - 1)
		ft_error("map incorrect", 1, data);
	if (data->map.map[y][x + 1] == ' ' || data->map.map[y][x - 1] == ' ')
		ft_error("map incorrect", 1, data);
	if (data->map.map[y + 1][x] == ' ' || data->map.map[y - 1][x] == ' ')
		ft_error("map incorrect", 1, data);
	if (data->map.map[y + 1][x - 1] == ' ' || data->map.map[y - 1]
		[x - 1] == ' ')
		ft_error("map incorrect", 1, data);
	if (data->map.map[y + 1][x + 1] == ' ' || data->map.map[y - 1]
		[x + 1] == ' ')
		ft_error("map incorrect", 1, data);
}

static void	cara_voisin(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
			if (ft_strchr("02NSEW", data->map.map[y][x]) != 0)
				voisin(data, x, y);
	}
}

void		check_map2(char **map, t_data *data)
{
	malloc_map(data);
	create_map(map, data);
	cara_voisin(data);
}
