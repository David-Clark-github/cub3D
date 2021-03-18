/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:09:45 by dclark            #+#    #+#             */
/*   Updated: 2021/03/10 21:12:28 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ceil_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (sp_line[++i])
	{
		if (ft_strlen(sp_line[i]) < 2 && flag != 1)
			elem_l->ceil = -1;
		else if (sp_line[i][0] == 'C' &&\
				(sp_line[i][1] == ' ' || sp_line[i][1] == '\t'))
		{
			elem_l->ceil = i;
			flag++;
		}
	}
	if (flag > 1)
		elem_l->ceil = -1;
}
