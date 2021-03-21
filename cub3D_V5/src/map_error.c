/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:34:46 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 10:27:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	map_error(t_map_err *map_err, char **map)
{
	if (check_map(map) == -1)
		return (-1);
	map_max(map_err, map);
	create_map(map_err, map);
	if (cara_voisin(map_err) == -1)
		return (-1);
	return (1);
}