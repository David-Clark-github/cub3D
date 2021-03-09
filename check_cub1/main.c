/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:01:00 by dclark            #+#    #+#             */
/*   Updated: 2021/03/08 14:02:57 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_elem_l	elem_l;
	t_elem_err	elem_err;
	int			fd;
	int			id_line;
	int			error_cub;
	char		*line_fd;
	char		**line_s;

	(void)(ac);
	fd = open(av[1], O_RDONLY);
	line_fd = file_line(fd);
	line_s = ft_split(line_fd, '\n');
	print_split_l(line_s);
	id_line = identify_lines(line_s, &elem_l);
	if (id_line == -1)
	{
		printf("Une ligne du fichier cub n'existe pas\n");
		print_elem_l(&elem_l);
		return (-1);
	}
	//init_elem_err(&elem_err, &elem_l, line_s);
	error_cub = check_error(&elem_err);
	if (error_cub == -1)
	{
		printf("Il y a une erreur\n");
	}
	print_elem_err(&elem_err);
}
