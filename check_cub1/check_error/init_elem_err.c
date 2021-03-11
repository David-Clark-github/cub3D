/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:11:22 by dclark            #+#    #+#             */
/*   Updated: 2021/03/11 11:45:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_elem_err(t_elem_err *elem_err, t_elem_l *el_l, char **line_s)
{
	t_map_err	map_err;

	elem_err->res = res_check_err(line_s[el_l->res]);
	elem_err->north = 0;
	elem_err->south = 0;
	elem_err->east = 0;
	elem_err->west = 0;
	elem_err->sprit = path_check_error(line_s[el_l->sprit]);
	elem_err->floor = 0;//path_check_error(line_s[el_l->floor]);
	elem_err->ceil = 0;//path_check_error(line_s[el_l->ceil]);
	elem_err->map = map_check_err(&map_err, line_s, el_l->map);
}
