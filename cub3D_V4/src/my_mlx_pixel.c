/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:35:59 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 13:09:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	my_mlx_pixel(t_map_img *map_img, int x, int y, int color)
{
	char    *dst;

    dst = map_img->addr + (y * map_img->line_l + x * (map_img->bpp / 8));
    *(unsigned int*)dst = color;
}
