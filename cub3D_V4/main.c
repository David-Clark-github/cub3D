/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:51:46 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 15:56:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "libft.h"

int main(int ac, char **av)
{
	t_elem_l	elem_l;
	t_elem_err	elem_err;
	t_pars		pars;
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
	pars.win.mlx = mlx_init();
	pars.win.win = mlx_new_window(pars.win.mlx, pars.res.x, pars.res.y, "cub3D");
//	mlx_hook(pars.win.win, 2, (1L<<0), func, &pars);
	map_to_image(&pars.img_a, &pars.map, &pars.win);
	mlx_put_image_to_window(pars.win.mlx, pars.win.win, pars.img_a.img, 0, 0);
	mlx_loop(pars.win.mlx);
	//print_pars(&pars);
}
