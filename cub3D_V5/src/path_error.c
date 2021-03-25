/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:31:00 by dclark            #+#    #+#             */
/*   Updated: 2021/03/25 13:10:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	end_xpm(char *line)
{
	if (ft_strncmp(&line[ft_strlen(line) - 4], ".xpm", 4) != 0)
		return (-1);
	return (1);
}

int	path_error(char *line)
{
	t_win	win;
	t_img_a	img;
	void	*res;
	int		i;

	i = 0;
	while (line[i] != '.' && line[i])
		i++;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 1, 1, "cub3D");
	res = mlx_xpm_file_to_image(win.mlx, &line[i], &img.width, &img.height);
	if (!res || end_xpm(line) == -1)
		return (-1);
	return (1);
}
