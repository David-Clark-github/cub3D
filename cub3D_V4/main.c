/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:51:46 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 14:04:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "libft.h"

int main(int ac, char **av)
{
	t_elem_l	elem_l;
	t_elem_err	elem_err;
	t_pars		pars;
	t_win		win;
	t_map_img	map_img;
	int			error_cub;
	char		**line_s;

	(void)ac;
	line_s = file_line_gnl(av[1]);
	if (identify_lines(line_s, &elem_l) == -1)
	{
		printf("Error\n");
		print_elem_l(&elem_l);
		return (-1);
	}
	init_elem_err(&elem_err, &elem_l, line_s);
	error_cub = check_error(&elem_err);
	if (error_cub == -1)
	{
		printf("Error\n");
		print_elem_err(&elem_err);
		return (-1);
	}
	parsing(line_s, &elem_l, &pars);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, pars.res.x, pars.res.y, "cub3D");
	map_to_image(&map_img, &pars.map, &win);
	mlx_put_image_to_window(win.mlx, win.win, map_img.img, 0, 0);
	mlx_loop(win.mlx);
	print_pars(&pars);
}
