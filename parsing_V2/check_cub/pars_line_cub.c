/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:33:32 by dclark            #+#    #+#             */
/*   Updated: 2021/03/01 13:11:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	return_line(char c1, char c2, char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (if line[0] == c1 && (line[1] == c2 || line[1] == '\t'))
			return (i);
		i++;
	}
	return (-1);
}

void		pars_line_cub(char **s_line, t_pars_l *pars)
{
	pars->res_l = return_line('R', ' ', s_line);
	pars->no_l = return_line('N', 'O', s_line);
	pars->so_l = return_line('S', 'O', s_line);
	pars->we_l = return_line('W', 'E', s_line);
	pars->ea_l = return_line('E', 'A', s_line);
	pars->sprit_l = return_line('S', ' ', s_line);
	pars->floor_l = return_line('F', ' ', s_line);
	pars->ceil_l = return_line('C', ' ', s_line);
}
