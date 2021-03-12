/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:54:38 by dclark            #+#    #+#             */
/*   Updated: 2021/03/12 14:14:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_err.h"

int	check_error(t_elem_err *el_err)
{
	int	res;

	res = 1;
	if (el_err->res == -1)
		res = -1;
	if (el_err->north == -1)
		res = -1;
	if (el_err->south == -1)
		res = -1;
	if (el_err->west == -1)
		res = -1;
	if (el_err->east == -1)
		res = -1;
	if (el_err->sprit == -1)
		res = -1;
	if (el_err->floor == -1)
		res = -1;
	if (el_err->ceil == -1)
		res = -1;
	if (el_err->map == -1)
		res = -1;
	return (res);
}
