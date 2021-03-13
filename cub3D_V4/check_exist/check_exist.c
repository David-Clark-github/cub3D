/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:21:02 by dclark            #+#    #+#             */
/*   Updated: 2021/03/13 14:24:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_line.h"

/*
** If all elements of elem_l exist it return 1
** otherwise 0 is return
*/

int	check_exist(t_elem_l *elem_l)
{
	int	res;

	res = 1;
	if (elem_l->res < 0)
		res = -1;
	if (elem_l->north < 0)
		res = -1;
	if (elem_l->south < 0)
		res = -1;
	if (elem_l->west < 0)
		res = -1;
	if (elem_l->east < 0)
		res = -1;
	if (elem_l->sprite < 0)
		res = -1;
	if (elem_l->floor < 0)
		res = -1;
	if (elem_l->ceil < 0)
		res = -1;
	if (elem_l->map < 0)
		res = -1;
	return (res);
}
