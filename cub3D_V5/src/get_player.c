/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:11:59 by dclark            #+#    #+#             */
/*   Updated: 2021/03/21 10:51:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static double 	direction_p(char c)
{
	if (c == 'N')
		return (PI / 2.0);
	else if (c == 'S')
		return ((3.0 * PI) / 2.0);
	else if (c == 'W')
		return (PI);
	else if (c == 'E')
		return (2.0 * PI);
	return (1.0);
}

void	get_player(t_player *player, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S')
			{
				player->pa = direction_p(map[y][x]);
				player->pos_x = x * SIZE;
				player->pos_y = y * SIZE;
			}
			if (map[y][x] == 'E' || map[y][x] == 'W')
			{
				player->pa = direction_p(map[y][x]);
				player->pos_x = x * SIZE;
				player->pos_y = y * SIZE;
			}
			x++;
		}
		y++;
	}
}
