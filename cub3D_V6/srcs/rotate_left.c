/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:50:54 by dclark            #+#    #+#             */
/*   Updated: 2021/04/05 11:34:20 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	rotate_left(t_ply *ply)
{
	double	old_plx;

	old_plx = ply->planx;
	ply->pa -= ply->rot_spd;
	if (ply->pa < 0)
		ply->pa += (2 * M_PI);
	ply->dirx = cosf(ply->pa);
	ply->diry = sinf(ply->pa);
	ply->planx = ply->planx * cosf(-ply->rot_spd) - \
	ply->plany * sinf(-ply->rot_spd);
	ply->plany = old_plx * sinf(-ply->rot_spd) + \
	ply->plany * cosf(-ply->rot_spd);
}
