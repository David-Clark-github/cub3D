/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:24:39 by dclark            #+#    #+#             */
/*   Updated: 2021/03/06 11:49:05 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_map(t_map_err *map)
{
	if (one_player_map(map->map) == -1)
		return (-1);
	if (empty_line_map(map->map) == -1)
		return (-1);
	return (1);
}
