/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 13:19:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 12:58:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#define PI 3.141592653589793

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

static void take_pos_ply(t_ply *ply, int x, int y, char c)
{
	ply->posx = x;
	ply->posy = y;
	if (c == 'N')
		ply->pa = PI / 2; 
	if (c == 'S')
		ply->pa = (3 * PI) / 2 ; 
	if (c == 'E')
		ply->pa = 0;
	if (c == 'W')
		ply->pa = PI;
}

static void	player_on_map(t_map *map, t_ply *ply)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (ft_isalpha(map->map[y][x]))
			{
				take_pos_ply(ply, x, y, map->map[y][x]);
				map->map[y][x] = '0';
				return;
			}
			x++;
		}
		y++;
	}
}

void	map_pars(char **line_s, t_pars *pars)
{
	map_max(line_s, &pars->map);
	create_map(line_s, &pars->map);
	player_on_map(&pars->map, &pars->player);
}
