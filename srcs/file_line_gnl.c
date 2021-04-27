/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:20:42 by dclark            #+#    #+#             */
/*   Updated: 2021/04/27 13:58:30 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "get_next_line.h"

static int	number_l(char *av, t_data *data)
{
	int		fd;
	int		gnl;
	int		res;
	char	*line;

	line = NULL;
	fd = open(av, O_RDONLY | O_NOFOLLOW);
	if (fd == -1)
		ft_error("erreur sur le fichier", 1, data);
	gnl = get_next_line(fd, &line);
	if (gnl != 0)
		res = 1;
	else
		res = 0;
	free(line);
	while (gnl != 0)
	{
		res++;
		gnl = get_next_line(fd, &line);
		free(line);
	}
	close(fd);
	data->nb_l = res;
	return (res);
}

char		**file_line_gnl(char *av, t_data *data)
{
	int		fd;
	int		num_l;
	int		dst_i;
	char	**dst;

	num_l = number_l(av, data);
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
