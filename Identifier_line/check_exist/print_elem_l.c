/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:34:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 12:44:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_elem_l(t_elem_l *elem_l)
{
	printf("res = %d\n", elem_l->res);
	printf("north = %d\n", elem_l->north);
	printf("south = %d\n", elem_l->south);
	printf("west = %d\n", elem_l->west);
	printf("east = %d\n", elem_l->east);
	printf("sprit = %d\n", elem_l->sprit);
	printf("floor = %d\n", elem_l->floor);
	printf("ceil = %d\n", elem_l->ceil);
	printf("map = %d\n", elem_l->map);
}
