/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:06:09 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 11:20:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	my_put_pixel(t_img_a *img_a, int x, int y, int color)
{
	char    *dst;

    dst = img_a->addr + (y * img_a->line_l + x * (img_a->bpp / 8));
    *(unsigned int*)dst = color;
}
