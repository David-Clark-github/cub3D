/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:00:22 by dclark            #+#    #+#             */
/*   Updated: 2021/03/16 15:07:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	turn_right(t_pars* pars)
{
	pars->player.pa += 0.1;
	if (pars->player.pa > 2.0 * PI)
		pars->player.pa -= (2.0 * PI);
	pars->player.pdx = cosf(pars->player.pa) * 2.0;
	pars->player.pdy = sinf(pars->player.pa) * 2.0;
}
