/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:00:42 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 16:21:07 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	malloc_map(t_data *data)
{
	int	y;

	y = -1;
	data->map.map = malloc(sizeof(char *) * data->map.map_h + 1);
	if (data->map.map == NULL)
		ft_error("La map n'as pas pu etre cree", 1, data);
	while (++y < data->map.map_h)
		data->map.map[y] = malloc(sizeof(char) * data->map.map_w);
}

static void	create_map(char **map, t_data *data)
{
	int	y;
	int	x;
	int	reste;

	y = -1;
	while(++y < data->map.map_h)
	{
		x = -1;
		reste = data->map.map_w - ft_strlen(map[y]);
		while (++x < ft_strlen(map[y]))
			data->map.map[y][x] = map[y][x];
		while(reste-- > 0)
			data->map.map[y][++x] = '1';
	}
	data->map.map[y] = 0;
}

void	check_map2(char **map, t_data *data)
{
	malloc_map(data);
	create_map(map, data);
}
