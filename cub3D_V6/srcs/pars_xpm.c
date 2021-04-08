/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:26:44 by dclark            #+#    #+#             */
/*   Updated: 2021/04/08 15:18:35 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_xpm(t_data *data, int t, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '.')
		i++;
	data->text[t].img = mlx_xpm_file_to_image(data->win.mlx, &line[i],
	&data->text[t].width, &data->text[t].height);
	if (data->text[t].img == NULL)
		ft_error("la texture n'a pas ete charger", 1, data);
	data->text[t].addr = mlx_get_data_addr(data->text[t].img,
	&data->text[t].bpp, &data->text[t].line_l, &data->text[t].endian);
}
