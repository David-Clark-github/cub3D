/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:24:38 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 15:36:20 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	toto_free(t_text *text)
{
	if (text->img != NULL)
		free(text->img);
	if (text->addr != NULL)
		free(text->addr);
}

void	free_text(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		toto_free(&data->text[i]);
		++i;
	}
}
