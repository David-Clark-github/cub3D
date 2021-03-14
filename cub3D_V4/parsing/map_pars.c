/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:19:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/14 15:47:30 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	map_max(char **line_s, t_map *map)
{
	int	y;

	y = 0;
	map->height = 0;
	map->width = 0;
	while (line_s[y])
	{
		if (ft_strlen(line_s[y]) > map->width)
			map->width = ft_strlen(line_s[y]);
		y++;
	}
	map->height = y;
}

static void	create_map(char **line_s, t_map *map)
{
	int	reste;
	int	y_l;
	int	x;

	y_l = -1;
	x = 0;
	map->map = malloc(sizeof(char *) * map->height + 1);
	while (++y_l < map->height)
		map->map[y_l] = malloc(sizeof(char) * map->width + 1);
	y_l = 0;
	while (y_l < map->height)
	{
		reste = map->width - ft_strlen(line_s[y_l]);
		map->map[y_l] = ft_strdup(line_s[y_l]);
		while (reste-- > 0)
		{
			map->map[y_l][ft_strlen(line_s[y_l]) + x] = ' ';
			x++;
		}
		x = 0;
		y_l++;
	}
}

void	map_pars(char **line_s, t_pars *pars)
{
	map_max(line_s, &pars->map);
	create_map(line_s, &pars->map);
}
