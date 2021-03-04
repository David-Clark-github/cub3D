/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:17:40 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 15:49:49 by dclark           ###   ########.fr       */
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
	if (identify_lines(split_line, &elem_l) == -1)
		return (-1);
	init_elem_check_1(&elem_c, &elem_l, split_line);
	/*printf("check_res = %d\n", elem_c.res);
	printf("check_floor = %d\n", elem_c.floor);
	printf("check_ceil = %d\n", elem_c.ceil);*/
}
