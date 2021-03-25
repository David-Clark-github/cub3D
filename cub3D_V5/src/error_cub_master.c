/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cub_master.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:11:22 by dclark            #+#    #+#             */
/*   Updated: 2021/03/25 13:12:45 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	error_cub_master(t_elem_err *elem_err, t_elem_l *el_l, char **line_s)
{
	elem_err->res = res_err(line_s[el_l->res]);
	elem_err->north = path_error(line_s[el_l->sprite]);
	elem_err->south = path_error(line_s[el_l->sprite]);
	elem_err->east = path_error(line_s[el_l->sprite]);
	elem_err->west = path_error(line_s[el_l->sprite]);
	elem_err->sprite = path_error(line_s[el_l->sprite]);
	elem_err->floor = floor_ceil_err(line_s[el_l->floor]);
	elem_err->ceil = floor_ceil_err(line_s[el_l->ceil]);
	elem_err->map = map_error(&elem_err->map_err, &line_s[el_l->map]);
	if (check_error(elem_err) == -1)
		return (-1);
	return (1);
}
