/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:24:11 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 16:30:37 by dclark           ###   ########.fr       */
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
//	print_data(&data);
	check_master(&data);
}
