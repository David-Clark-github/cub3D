/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:33:17 by dclark            #+#    #+#             */
/*   Updated: 2021/04/08 15:19:41 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_floor(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	data->floor.r = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	data->floor.g = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	data->floor.b = ft_atoi(&line[i]);
	data->floor.color = trgb(0, data->floor.r, data->floor.g, data->floor.b);
}
