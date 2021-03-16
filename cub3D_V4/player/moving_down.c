/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:51:31 by dclark            #+#    #+#             */
/*   Updated: 2021/03/16 15:05:51 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	moving_down(t_pars *pars)
{
	pars->player.posx -= pars->player.pdx;
	pars->player.posy -= pars->player.pdy;
}
