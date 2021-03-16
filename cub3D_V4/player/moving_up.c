/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:51:31 by dclark            #+#    #+#             */
/*   Updated: 2021/03/16 15:05:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	moving_up(t_pars *pars)
{
	pars->player.posx += pars->player.pdx;
	pars->player.posy += pars->player.pdy;
}
