/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:46:43 by dclark            #+#    #+#             */
/*   Updated: 2021/03/12 14:15:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_err.h"

int	empty_line_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) == 0)
			return (-1);
		y++;
	}
	return (1);
}
