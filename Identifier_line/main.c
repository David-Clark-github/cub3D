/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:17:40 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 12:08:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int main(int ac, char **av)
{
	t_elem_l	elem_l;
	t_elem_c	elem_c;
	int		fd;
	char	*line_fd;
	char	**split_line;

	fd = open(av[1], O_RDONLY);
	line_fd = file_line(fd);
	split_line = ft_split(line_fd, '\n');
//	print_split_l(split_line);
	identify_lines(split_line, &elem_l);
	print_elem_l(&elem_l);
	init_elem_check(&elem_c);
//	print_elem_check(&elem_c);
	elem_c.res = res_check_err(split_line[elem_l.res]);
	elem_c.floor = floor_check_err(split_line[elem_l.floor]);
	printf("check_res = %d\n", elem_c.res);
	printf("check_floor = %d\n", elem_c.floor);
}
