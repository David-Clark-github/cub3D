/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:26:34 by dclark            #+#    #+#             */
/*   Updated: 2021/03/03 11:37:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	res_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (sp_line[++i])
	{
		if (ft_strlen(sp_line[i]) < 2)
			elem_l->res = -1;
		if (sp_line[i][0] == 'R' &&\
				(sp_line[i][1] == ' ' || sp_line[i][1] == '\t'))
		{
			elem_l->res = i;
			flag++;
		}
	}
	if (flag > 1)
		elem_l->res = -1;
}
