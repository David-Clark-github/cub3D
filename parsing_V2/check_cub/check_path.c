/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:06:33 by dclark            #+#    #+#             */
/*   Updated: 2021/02/27 12:05:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int check_path(char *line, t_win *win, t_img *img)
{
	int		i;
	void	*res;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	}
	res = mlx_xpm_file_to_image(win->mlx_ptr, \
			&line[i], &img->width, &img->height);
	if (res == NULL)
		return (-1);
	return (1);
}
