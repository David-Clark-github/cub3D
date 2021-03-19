/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:31:00 by dclark            #+#    #+#             */
/*   Updated: 2021/03/19 14:46:06 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	path_error(char *line)
{
	t_win	win;
	t_img	img;
	void	*res;
	int		i;

	i = 0;
	while (line[i] != '.' && line[i])
		i++;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1, 1, "cub3D");
	res = mlx_xpm_file_to_image(win.mlx, &line[i], &img.width, &img.height);
	if (!res)
	{
		printf("res = %p\n", res);
		return (-1);
	}
	return (1);
}
