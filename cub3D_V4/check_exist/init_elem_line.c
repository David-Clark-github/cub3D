/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elem_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:57:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/13 14:25:07 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_line.h"

void	init_elem_line(t_elem_l *elem_l)
{
	elem_l->res = -1;
	elem_l->north = -1;
	elem_l->south = -1;
	elem_l->west = -1;
	elem_l->east = -1;
	elem_l->sprite = -1;
	elem_l->floor = -1;
	elem_l->ceil = -1;
	elem_l->map = -1;
}