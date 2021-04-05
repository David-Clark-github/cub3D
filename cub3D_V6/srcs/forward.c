/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:23:18 by dclark            #+#    #+#             */
/*   Updated: 2021/04/05 11:32:49 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	forward(t_ply *ply, t_mapou *mapou)
{
	if (mapou->map[(int)ply->posy][(int)ply->posx + ply->dirx * ply->mv_spd] \
		== 0)
		ply->posx += ply->dirx * ply->mv_spd;
	if (mapou->map[(int)ply->posy + ply->diry * ply->mv_spd][(int)ply->posx] \
		== 0)
		ply->posy += ply->diry * ply->mv_spd;
}
