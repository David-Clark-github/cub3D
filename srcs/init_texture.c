/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:14:41 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 11:33:08 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_texture(char *path, t_text *text, t_win *win)
{
	text->img = mlx_xpm_file_to_image(win->mlx, path, \
	&text->width, &text->height);
	text->addr = mlx_get_data_addr(text->img, &text->bpp, &text->line_l, \
	&text->endian);
}
