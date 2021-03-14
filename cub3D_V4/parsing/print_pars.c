/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:42:35 by dclark            #+#    #+#             */
/*   Updated: 2021/03/14 15:49:43 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_pars(t_pars *pars)
{
	printf("res x = %d\n", pars->res.x);
	printf("res y = %d\n", pars->res.y);
	printf("img_north = %p\n", pars->north.img);
	printf("img_south = %p\n", pars->south.img);
	printf("img_west = %p\n", pars->west.img);
	printf("img_east = %p\n", pars->east.img);
	printf("img_sprite = %p\n", pars->sprite.img);
	printf("ceil R = %d G = %d B = %d\n", pars->ceil.R, pars->ceil.G, pars->ceil.B);
	printf("floor R = %d G = %d B = %d\n", pars->floor.R, pars->floor.G, pars->floor.B);
	print_split_l(pars->map.map);
}
