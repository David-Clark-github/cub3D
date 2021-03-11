/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:01:00 by dclark            #+#    #+#             */
/*   Updated: 2021/03/11 14:30:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_elem_l	elem_l;
	t_elem_err	elem_err;
	int			error_cub;
	char		**line_s;

	(void)(ac);
	line_s = file_line_gnl(av[1]);
//	print_split_l(line_s);
	if (identify_lines(line_s, &elem_l) == -1)
	{
		printf("Une ligne du fichier cub n'existe pas ou invalide\n");
		print_elem_l(&elem_l);
		return (-1);
	}
//	else
//		print_elem_l(&elem_l);
	init_elem_err(&elem_err, &elem_l, line_s);
	error_cub = check_error(&elem_err);
	if (error_cub == -1)
	{
		printf("Error\n");
		//print_elem_err(&elem_err);
	}
}
