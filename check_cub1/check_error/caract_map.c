/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caract_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:02:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/11 12:14:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check(char c)
{
	if (c == ' ')
		return (1);
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == '2')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	return (-1);
}

int	caract_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (check(map[y][x]) == -1)
				return (-1);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
