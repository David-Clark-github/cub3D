/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:22:37 by dclark            #+#    #+#             */
/*   Updated: 2021/02/22 14:57:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	count_number(char *line)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (line[i])
	{
		while (ft_isdigit(line[i]) == 0)
			i++;
		if (ft_isdigit(line[i]))
			res++;
		while (ft_isdigit(line[i]))
			i++;
	}
	return (res);
}

static int	count_comma(char *line)
{
	int res;
	int	i;

	res = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			res++;
		i++;
	}
	return (res);
}

/*
** int i start at 1 because we know that the fisrt caracter is the letter 'F'
*/

int	check_floor(char *line)
{
	int	i;
	int	num_count;
	int	comma_count;

	comma_count = count_comma(line);
	num_count = count_number(line);
	printf("num_count = %d\n", num_count);
	if (num_count == 3 && comma_count == 3)
		return (1);
	else
		return (-1);
}
