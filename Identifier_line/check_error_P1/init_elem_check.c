/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:41:42 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 14:20:18 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_elem_check_1(t_elem_c *elem_check, t_elem_l *el_l, char **line_s)
{
	t_map_err	map_err;

	elem_check->res = res_check_err(line_s[el_l->res]);
	elem_check->floor = floor_check_err(line_s[el_l->floor]);
	elem_check->ceil = ceiling_check_err(line_s[el_l->ceil]);
	elem_check->map = map_check_err(&map_err, line_s, el_l->map);
}
