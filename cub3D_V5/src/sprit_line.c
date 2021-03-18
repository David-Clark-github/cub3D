/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:12:11 by dclark            #+#    #+#             */
/*   Updated: 2021/03/13 14:26:39 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	sprit_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (sp_line[++i])
	{
		if (ft_strlen(sp_line[i]) < 2 && flag != 1)
			elem_l->sprite = -1;
		else if (sp_line[i][0] == 'S' &&\
				(sp_line[i][1] == ' ' || sp_line[i][1] == '\t'))
		{
			elem_l->sprite = i;
			flag++;
		}
	}
	if (flag != 1)
		elem_l->sprite = -1;
}
