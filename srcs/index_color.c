/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:34:05 by dclark            #+#    #+#             */
/*   Updated: 2021/04/09 16:36:45 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	index_color(int x, int y, t_text *text)
{
	int	index;

	index = (y * text->line_l + x * (text->bpp / 8));
	return (((int *)text->addr)[index / 4]);
}
