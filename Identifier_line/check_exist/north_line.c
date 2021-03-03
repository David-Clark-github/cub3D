/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:03:56 by dclark            #+#    #+#             */
/*   Updated: 2021/03/03 11:36:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	north_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (sp_line[++i])
	{
		if (ft_strlen(sp_line[i]) < 2)
			elem_l->north = -1;
		else if (sp_line[i][0] == 'N' && sp_line[i][1] == 'O')
		{
			elem_l->north = i;
			flag++;
		}
	}
	if (flag > 1)
		elem_l->north = -1;
}
