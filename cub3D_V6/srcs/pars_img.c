/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:38:39 by dclark            #+#    #+#             */
/*   Updated: 2021/04/10 10:40:21 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_img(t_img *img, t_win *win)
{
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_l,
	&img->endian);
}