/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:41:42 by dclark            #+#    #+#             */
/*   Updated: 2021/03/03 14:24:26 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void init_elem_check(t_elem_c *elem_check)
{
	elem_check->res = 0;
	elem_check->north = 0;
	elem_check->south = 0;
	elem_check->west = 0;
	elem_check->east = 0;
	elem_check->sprit = 0;
	elem_check->floor = 0;
	elem_check->ceil = 0;
	elem_check->map = 0;
}
