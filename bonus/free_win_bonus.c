/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:06:44 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 16:09:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_win(t_win *win)
{
	if (win->win != NULL)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx != NULL)
		mlx_destroy_display(win->mlx);
	free(win->mlx);
}
