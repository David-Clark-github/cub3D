/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crabe_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:36:13 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 11:57:51 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	crabe_left(t_ply *ply)
{
	double	old_pa;

	old_pa = ply->pa;
	ply->pa -= (2 * M_PI / 4);
	if (ply->pa < 0)
		ply->pa += (2 * M_PI);
	ply->dirx = cosf(ply->pa);
	ply->diry = sinf(ply->pa);
	if (map[(int)(ply->posy)][(int)(ply->posx + ply->dirx * ply->mv_spd * 2)] \
		== 0)
		ply->posx += ply->dirx * ply->mv_spd;
	if (map[(int)(ply->posy + ply->diry * ply->mv_spd * 2)][(int)(ply->posx)] \
		== 0)
		ply->posy += ply->diry * ply->mv_spd;
	ply->pa = old_pa;
	ply->dirx = cosf(ply->pa);
	ply->diry = sinf(ply->pa);
}
