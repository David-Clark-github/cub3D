/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:12:54 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 15:20:47 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_ply(t_ply *ply)
{
	ply->pa = 0;
	ply->posx = 0;
	ply->posy = 0;
	ply->dirx = 0;
	ply->diry = 0;
	ply->planx = 0;
	ply->plany = 0;
	ply->rot_spd = 0;
	ply->mv_spd = 0;
}
