/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:02:11 by user42            #+#    #+#             */
/*   Updated: 2021/03/13 11:15:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	texture_pars(char *line, t_pars *pars)
{
	int		i;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, pars->res->x, pars->res->y, "cub3D");
	i = 0;
	while (line[i] != '.')
		i++;
	pars->north->img = mlx_xpm_file_to_image(mlx, &line[i], \
		pars->north->width, pars->north->height);
}