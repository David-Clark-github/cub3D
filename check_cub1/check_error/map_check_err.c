/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 13:37:39 by dclark            #+#    #+#             */
/*   Updated: 2021/03/11 14:00:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	create_map(t_map_err *map, char **line_s, int map_st)
{
	int i = 0;
	int	reste;
	int	y_l = 0;

	map->map = malloc(sizeof(char *) * map->y_max + 1);
	while (i < map->y_max)
	{
		map->map[i] = malloc(sizeof(char) * map->x_max);
		i++;;
	}
	i = 0;
	while (y_l < map->y_max)
	{
		reste = map->x_max - ft_strlen(line_s[y_l + map_st]);
		while (line_s[y_l + map_st][i])
		{
			map->map[y_l][i] = line_s[y_l + map_st][i];
			i++;
		}
		while (reste--)
			map->map[y_l][i++] = ' ';

		i = 0;
		y_l++;
	}
	map->map[y_l] = 0;
}

void	map_max(t_map_err *map, char **line_s, int map_st)
{
	int	y;

	y = 0;
	map->x_max = 0;
	map->y_max = 0;
	while (line_s[y + map_st])
	{
		if (ft_strlen(line_s[y + map_st]) > map->x_max)
			map->x_max = ft_strlen(line_s[y + map_st]);
		y++;
	}
	map->y_max = y;
}

int	map_check_err(t_map_err *map_err, char **line_s, int map_st)
{
	if (check_map(&line_s[map_st]) == -1)
		return(-1);
	map_max(map_err, line_s, map_st);
	create_map(map_err, line_s, map_st);
	if (cara_voisin(map_err) == -1)
		return (-1);	
	return (1);
}
