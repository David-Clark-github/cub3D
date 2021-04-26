/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:20:42 by dclark            #+#    #+#             */
/*   Updated: 2021/04/26 14:25:43 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "get_next_line.h"

static int	number_l(char *av)
{
	int		fd;
	int		gnl;
	int		res;
	char	*line;

	res = 0;
	line = NULL;
	fd = open(av, O_RDONLY | O_NOFOLLOW);
	if (fd == -1)
		ft_error("erreur sur le fichier", 1, 0);
	gnl = get_next_line(fd, &line);
	free(line);
	while (gnl != 0)
	{
		res++;
		gnl = get_next_line(fd, &line);
		free(line);
	}
	close(fd);
	return (res);
}

char		**file_line_gnl(char *av)
{
	int		fd;
	int		num_l;
	int		dst_i;
	char	**dst;

	num_l = number_l(av);
	fd = open(av, O_RDONLY);
	dst_i = 0;
	dst = malloc(sizeof(char *) * (num_l + 1));
	while (num_l--)
	{
		get_next_line(fd, &dst[dst_i]);
		dst_i++;
	}
	dst[dst_i] = 0;
	close(fd);
	return (dst);
}
