/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:26:34 by dclark            #+#    #+#             */
/*   Updated: 2021/03/10 21:10:47 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_line.h"

void	res_line(char **line_s, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	elem_l->res = -1;
	while (line_s[++i])
	{
		if (ft_strlen(line_s[i]) >= 2)
		{
			if (line_s[i][0] == 'R' &&\
					(line_s[i][1] == ' ' || line_s[i][1] == '\t'))
			{
				elem_l->res = i;
				flag++;
			}
		}
	}
	if (flag > 1)
		elem_l->res = -1;
}
