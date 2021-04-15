/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:38:39 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 16:21:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_img(t_img *img, t_win *win, t_data *data)
{
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	if (!(img->img))
		ft_error("echec de mlx_new_image", 1, data);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_l,
	&img->endian);
	if (!(img->addr))
		ft_error("echec de mlx_get_data_addr", 1, data);
}
