/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:36:19 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 14:54:57 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_res(t_win *win, char *line)
{
	int	i;

	i = 0;
	mlx_get_screen_size(win->mlx, &win->width, &win->height);
		while (!ft_isdigit(line[i]))
			i++;
		if (ft_atoi(&line[i]) < win->width)
			win->width = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		while (!ft_isdigit(line[i]))
			i++;
		if (ft_atoi(&line[i]) < win->height)
			win->height = ft_atoi(&line[i]);
	win->win = mlx_new_window(win->mlx, win->width, win->height, "cub3D");
}
