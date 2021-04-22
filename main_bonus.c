/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:24:11 by dclark            #+#    #+#             */
/*   Updated: 2021/04/22 12:05:47 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_ac_av(ac, av);
	init_data(&data);
	data.raw_cub = file_line_gnl(av[1]);
	id_line_master(&data);
	check_master(&data);
	parsing_master(&data);
	floor_ceil_texture(&data.f_c, &data);
	algo(&data);
	if (ac == 3)
		ft_save(&data);
	else
	{
		data.win.win = mlx_new_window(data.win.mlx, data.win.width,
		data.win.height, "cub3D");
		exec(&data);
	}
}
