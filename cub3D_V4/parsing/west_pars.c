/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:02:11 by user42            #+#    #+#             */
/*   Updated: 2021/03/13 14:08:27 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	west_pars(char *line, t_pars *pars)
{
	int		i;
	void	*mlx;

	mlx = mlx_init();
	i = 0;
	while (line[i] != '.')
		i++;
	pars->west.img = mlx_xpm_file_to_image(mlx, &line[i], \
		&pars->west.width, &pars->west.height);
}
