/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:24:38 by dclark            #+#    #+#             */
/*   Updated: 2021/04/08 15:51:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	toto_free(t_data *data, t_text *text)
{
	if (text->img != NULL)
		mlx_destroy_image(data->win.mlx, text->img);
	if (text->addr != NULL)
		free(text->addr);
}

void		free_text(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		toto_free(data, &data->text[i]);
}
