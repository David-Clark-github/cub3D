/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:26:44 by dclark            #+#    #+#             */
/*   Updated: 2021/04/21 10:36:17 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	pars_xpm(t_data *data, int t, char *line)
{
	int	i;

	i = 0;
	while (ft_isalpha(line[i]) && line[i])
		++i;
	while (line[i] != '.')
	{
		if (!ft_isspace(line[i]))
			ft_error("La ligne a un défaut", 1, data);
		i++;
	}
	data->text[t].img = mlx_xpm_file_to_image(data->win.mlx, &line[i],
	&data->text[t].width, &data->text[t].height);
	if (data->text[t].img == NULL)
		ft_error("la texture n'a pas été charger xpm_to_file", 1, data);
	data->text[t].addr = mlx_get_data_addr(data->text[t].img,
	&data->text[t].bpp, &data->text[t].line_l, &data->text[t].endian);
	if (data->text[t].addr == NULL)
		ft_error("la texture n'a pas ete charger get_data_addr", 1, data);
}
