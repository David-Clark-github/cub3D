/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:25:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 12:58:58 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	identify_lines(char **sp_line, t_elem_l *elem_l)
{
	init_elem_line(elem_l);
	res_line(sp_line, elem_l);
	north_line(sp_line, elem_l);
	south_line(sp_line, elem_l);
	west_line(sp_line, elem_l);
	east_line(sp_line, elem_l);
	sprit_line(sp_line, elem_l);
	floor_line(sp_line, elem_l);
	ceil_line(sp_line, elem_l);
	map_line(sp_line, elem_l);
	if (check_exist(elem_l) == 0)
		return (-1);
	return (1);
}
