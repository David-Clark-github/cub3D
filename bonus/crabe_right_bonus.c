/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crabe_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:36:13 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 11:18:53 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	crabe_right(t_ply *ply, char **map)
{
	double	old_pa;

	old_pa = ply->pa;
	ply->pa += (2 * M_PI / 4);
	if (ply->pa > 2 * M_PI)
		ply->pa -= (2 * M_PI);
	ply->dirx = cosf(ply->pa);
	ply->diry = sinf(ply->pa);
	if (map[(int)(ply->posy)][(int)(ply->posx + ply->dirx * ply->mv_spd * 2)] \
		== '0')
		ply->posx += ply->dirx * ply->mv_spd;
	if (map[(int)(ply->posy + ply->diry * ply->mv_spd * 2)][(int)(ply->posx)] \
		== '0')
		ply->posy += ply->diry * ply->mv_spd;
	ply->pa = old_pa;
	ply->dirx = cosf(ply->pa);
	ply->diry = sinf(ply->pa);
}
