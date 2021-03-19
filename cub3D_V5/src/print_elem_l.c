/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:34:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_elem_l(t_elem_l *elem_l)
{
	printf("%-10s = %2d\n", "resolution", elem_l->res);
	printf("%-10s = %2d\n", "north", elem_l->north);
	printf("%-10s = %2d\n", "south", elem_l->south);
	printf("%-10s = %2d\n", "west", elem_l->west);
	printf("%-10s = %2d\n", "east", elem_l->east);
	printf("%-10s = %2d\n", "sprite", elem_l->sprite);
	printf("%-10s = %2d\n", "floor", elem_l->floor);
	printf("%-10s = %2d\n", "ceil", elem_l->ceil);
	printf("%-10s = %2d\n", "map", elem_l->map);
}
