/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:27:48 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 11:14:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int main(int ac, char **av)
{
	t_data	data;

	if (check_ac_av(ac, av) == -1)
	{	
		printf("error ac av\n");
		return (-1);
	}
	data.raw_cub_l = file_line_gnl(av[1]);
	if (id_line_master(data.raw_cub_l, &data.elem_l) == -1)
	{
		printf("error line\n");
		print_elem_l(&data.elem_l);
		return (-1);
	}
	if (error_cub_master(&data.elem_err, &data.elem_l, data.raw_cub_l) == -1)
	{
		printf("error\n");
		print_elem_err(&data.elem_err);
		return (-1);
	}	
	parsing_master(&data);
	return (1);
}
