/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:07:14 by dclark            #+#    #+#             */
/*   Updated: 2021/03/10 21:11:29 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	west_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (sp_line[++i])
	{
		if (ft_strlen(sp_line[i]) < 2 && flag != 1)
			elem_l->west = -1;
		else if (sp_line[i][0] == 'W' && sp_line[i][1] == 'E')
		{
			elem_l->west = i;
			flag++;
		}
	}
	if (flag > 1)
		elem_l->west = -1;
}
