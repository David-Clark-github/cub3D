/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:06:33 by dclark            #+#    #+#             */
/*   Updated: 2021/02/25 12:06:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int check_path(char *line)
{
	int	i;
	int	fd;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	fd = open(&line[i], O_RDONLY);
	if (fd < 0)
		return (-1);
	else
	{
		close(fd);
		return (1);
	}
}
