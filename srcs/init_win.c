/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:01:24 by dclark            #+#    #+#             */
/*   Updated: 2021/04/09 10:49:29 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_win(t_win *win)
{
	win->mlx = mlx_init();
	win->win = NULL;
	mlx_get_screen_size(win->mlx, &win->width, &win->height);
}
