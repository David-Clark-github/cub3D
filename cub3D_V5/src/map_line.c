/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:16:18 by dclark            #+#    #+#             */
/*   Updated: 2021/03/11 14:45:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	char_set_coco(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	return (0);
}

void		map_line(char **sp_line, t_elem_l *elem_l)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (sp_line[++i] && flag == 0)
	{
		if (ft_strlen(sp_line[i]) < 1)
			elem_l->map = -1;
		else if (char_set_coco(sp_line[i][0]) == 1)
		{
			elem_l->map = i;
			flag = 1;
		}
	}
}
