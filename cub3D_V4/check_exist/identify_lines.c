/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:25:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/12 13:30:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_line.h"

int	identify_lines(char **line_s, t_elem_l *elem_l)
{
	init_elem_line(elem_l);
	res_line(line_s, elem_l);
	north_line(line_s, elem_l);
	south_line(line_s, elem_l);
	west_line(line_s, elem_l);
	east_line(line_s, elem_l);
	sprit_line(line_s, elem_l);
	floor_line(line_s, elem_l);
	ceil_line(line_s, elem_l);
	map_line(line_s, elem_l);
	if (check_exist(elem_l) == -1)
		return (-1);
	return (1);
}
