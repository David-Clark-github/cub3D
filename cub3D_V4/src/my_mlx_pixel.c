/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:35:59 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 14:42:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	my_mlx_pixel(t_img_a *img_a, int x, int y, int color)
{
	char    *dst;

    dst = img_a->addr + (y * img_a->line_l + x * (img_a->bpp / 8));
    *(unsigned int*)dst = color;
}
