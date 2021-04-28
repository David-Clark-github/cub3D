/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:20:19 by dclark            #+#    #+#             */
/*   Updated: 2021/04/28 14:30:34 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	free_text2(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (data->text[i].img != NULL)
			mlx_destroy_image(data->win.mlx, data->text[i].img);
}

static void	free_raw_cub(char **raw_cub, int nb_l)
{
	int	i;

	i = -1;
	while (++i < nb_l)
		free(raw_cub[i]);
		i++;
	}
	if (ft_strlen(raw_cub[nb_l]) == 0)
		free(raw_cub[nb_l]);
	free(raw_cub);
}

void		ft_empty_data(t_data *data)
{
	if (!data)
		return ;
	if (data->raw_cub != NULL)
		free_raw_cub(data->raw_cub, data->nb_l);
	free_ray(&data->ray);
	free_text2(data);
	free_map(&data->map);
	if (data->sp != NULL)
		free(data->sp);
	free_img(&data->img, &data->win);
	free_win(&data->win);
}
