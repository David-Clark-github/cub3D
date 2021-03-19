/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:34:46 by dclark            #+#    #+#             */
/*   Updated: 2021/03/19 16:41:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	map_error(t_map_err *map_err, char **map)
{
	if (check_map(map) == -1)
		return (-1);
	print_split_l(map);
	map_max(map_err, map);
	printf("x_max = %d\n", map_err->x_max);
	printf("y_max = %d\n", map_err->y_max);
	create_map(map_err, map);
	print_split_l(map_err->map);
	if (cara_voisin(map_err) == -1)
		return (-1);
	return (1);
}
