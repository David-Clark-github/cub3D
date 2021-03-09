/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:31:00 by dclark            #+#    #+#             */
/*   Updated: 2021/03/07 16:19:22 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	path_check_error(char *line)
{
	t_win	win;
	t_img	img;
	void	*res;

	win.mlx = mlx_init();
	win.win = mlx_new_window(&win.mlx, 1, 1, "toto");
	res = mlx_xpm_file_to_image(&win.mlx, line, &img.width, &img.height);
	if (!res)
		return (-1);
	return (1);
}
