/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   south_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:05:59 by dclark            #+#    #+#             */
/*   Updated: 2021/03/10 21:11:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_line.h"

void	south_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag = 0;

	i = -1;
	while (sp_line[++i])
	{
		if (ft_strlen(sp_line[i]) < 2 && flag != 1)
			elem_l->south = -1;
		else if (sp_line[i][0] == 'S' && sp_line[i][1] == 'O')
		{
			elem_l->south = i;
			flag++;
		}
	}
	if (flag > 1)
		elem_l->south = -1;
}
