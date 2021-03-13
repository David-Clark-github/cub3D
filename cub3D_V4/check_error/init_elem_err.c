/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:11:22 by dclark            #+#    #+#             */
/*   Updated: 2021/03/13 14:27:16 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_err.h"

void	init_elem_err(t_elem_err *elem_err, t_elem_l *el_l, char **line_s)
{
	t_map_err	map_err;

	elem_err->res = res_check_err(line_s[el_l->res]);
	elem_err->north = 1;
	elem_err->south = 1;
	elem_err->east = 1;
	elem_err->west = 1;
	elem_err->sprit = path_check_error(line_s[el_l->sprite]);
	elem_err->floor = floor_check_err(line_s[el_l->floor]);
	elem_err->ceil = floor_check_err(line_s[el_l->ceil]);
	elem_err->map = map_check_err(&map_err, line_s, el_l->map);
}
