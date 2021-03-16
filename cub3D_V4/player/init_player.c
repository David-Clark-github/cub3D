/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:19:59 by dclark            #+#    #+#             */
/*   Updated: 2021/03/16 14:50:06 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#define PI 3.141592653589793


static int	ft_char_set(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static double	direction(t_pars *pars, int y, int x)
{
	pars->player.posx = (double)x;
	pars->player.posy = (double)y;
	if (pars->map.map[y][x] == 'N')
		pars->player.pa = PI / 2.0;
	if (pars->map.map[y][x] == 'S')
		pars->player.pa = (3.0 * PI) / 2.0;
	if (pars->map.map[y][x] == 'E')
		pars->player.pa = 0.0;
	if (pars->map.map[y][x] == 'W')
		pars->player.pa = PI;
}

void	init_player(t_pars *pars)
{
	int	x;
	int	y;

	y = -1;
	while (pars->map.map[++y])
	{
		x = -1;
		while (pars->map.map[y][++x])
		{
			if (ft_char_set(pars->map.map[y][x]) == 1)
				direction(pars, y, x);
		}
	}
}
