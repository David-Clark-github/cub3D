/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:20:19 by dclark            #+#    #+#             */
/*   Updated: 2021/04/09 10:46:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	free_raw_cub(char **raw_cub)
{
	int	i;

	i = -1;
	while (raw_cub[++i])
		free(raw_cub[i]);
	free(raw_cub);
}

void		ft_empty_data(t_data *data)
{
	if (!data)
		return ;
	if (data->raw_cub != NULL)
		free_raw_cub(data->raw_cub);
	free_win(&data->win);
	free_img(&data->img);
	free_ray(&data->ray);
	free_text(data);
	free_map(&data->map);
	if (data->sp != NULL)
		free(data->sp);
}
