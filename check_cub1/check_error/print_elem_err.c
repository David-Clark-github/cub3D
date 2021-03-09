/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:38:45 by dclark            #+#    #+#             */
/*   Updated: 2021/03/07 14:09:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void    print_elem_err(t_elem_err *elem_check)
{
	printf("res = %d\n", elem_check->res);
	printf("north = %d\n", elem_check->north);
	printf("south = %d\n", elem_check->south);
	printf("west = %d\n", elem_check->west);
	printf("east = %d\n", elem_check->east);
	printf("sprit = %d\n", elem_check->sprit);
	printf("floor = %d\n", elem_check->floor);
	printf("ceil = %d\n", elem_check->ceil);
	printf("map = %d\n", elem_check->map);
}
