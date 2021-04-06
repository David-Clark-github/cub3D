/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:10:58 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 11:12:30 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->line_l = 0;
	img->bpp = 0;
	img->width = 0;
	img->height = 0;
	img->endian = 0;
}
