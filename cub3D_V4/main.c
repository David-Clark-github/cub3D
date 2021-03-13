/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:51:46 by dclark            #+#    #+#             */
/*   Updated: 2021/03/13 13:43:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
	print_pars(&pars);
}
