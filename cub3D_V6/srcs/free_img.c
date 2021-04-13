/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:09:26 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 15:55:05 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_img(t_img *img, t_win *win)
{
	if (img->img != NULL)
		mlx_destroy_image(win->mlx, img->img);
/*	if (img->addr != NULL)
		free(img->addr); */
}
