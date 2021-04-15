/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:27:03 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 13:15:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	titi_text(t_text *text)
{
	text->img = NULL;
	text->addr = NULL;
	text->line_l = 0;
	text->bpp = 0;
	text->width = 0;
	text->height = 0;
	text->endian = 0;
}

void		init_text(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		titi_text(&data->text[i]);
}
