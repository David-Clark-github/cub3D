/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:02:32 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 15:52:49 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "include.h"
#define PI 3.141592653589793


static void	erase_frame(t_pars *pars)
{
	int	n;

	n = 4 * pars->res.x * pars->res.y;
	while (--n >= 0)
		pars->img_a.addr[n] = create_trgb(0, 255, 0, 0);
}

void	ft_close(void)
{
	exit(EXIT_SUCCESS);
}

int	func(int keycode, void *param)
{
	t_pars	*pars;

	pars = param;
	map_to_image(&pars->img_a, &pars->map, &pars->win);
	pars->player.pdx = cosf(pars->player.pa) * 2.0;
	pars->player.pdy = sinf(pars->player.pa) * 2.0;
	if (keycode == 53)
		ft_close();
	if (keycode == 119) //AVANCE W
	{
		pars->player.posx += pars->player.pdx;
		pars->player.posy += pars->player.pdy;
	}
	if (keycode == 115) //RECULER S
	{
		pars->player.posx -= pars->player.pdx;
		pars->player.posy -= pars->player.pdy;
	}
	if (keycode == 65361) // TOURNER A GAUCHE
	{
		pars->player.pa -= 0.1;
		if (pars->player.pa < 0)
			pars->player.pa += (2.0 * PI);
		pars->player.pdx = cosf(pars->player.pa) * 2.0;
		pars->player.pdy = sinf(pars->player.pa) * 2.0;
	}
	if (keycode == 65363) // TOURNER A DROITE
	{
		pars->player.pa += 0.1;
		if (pars->player.pa > (2.0 * PI))
			pars->player.pa -= (2.0 * PI);
		pars->player.pdx = cosf(pars->player.pa) * 2.0;
		pars->player.pdy = sinf(pars->player.pa) * 2.0;
	}
	erase_frame(pars);
	my_mlx_pixel(&pars->img_a, pars->player.posx * 10, pars->player.posy * 10, create_trgb(0, 255, 0, 0));
	mlx_put_image_to_window(pars->win.mlx, pars->win.win, pars->img_a.img, 0, 0);
	return (1);
}
