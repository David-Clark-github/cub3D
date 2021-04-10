/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:36:19 by dclark            #+#    #+#             */
/*   Updated: 2021/04/10 14:51:50 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_res(t_data *data, char *line)
{
	int	i;

	i = 0;
	mlx_get_screen_size(data->win.mlx, &data->win.width, &data->win.height);
	while (!ft_isdigit(line[i]))
		i++;
	if (ft_atoi(&line[i]) < data->win.width)
		data->win.width = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	if (ft_atoi(&line[i]) < data->win.height)
		data->win.height = ft_atoi(&line[i]);
	data->img.img = mlx_new_image(data->win.mlx, data->win.width,
	data->win.height);
}
