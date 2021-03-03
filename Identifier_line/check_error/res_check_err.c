/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_check_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:02:13 by dclark            #+#    #+#             */
/*   Updated: 2021/03/03 14:54:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	num_count(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == 'R')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			res++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (res);
}

static int	min_max_res(char *str)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	if (str[i] == 'R')
		i++;
	x = 0;
	y = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	x = ft_atoi(&str[i]);
	if (x < 1)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	y = ft_atoi(&str[i]);
	if (y < 1)
		return (-1);
	if (x == 0 || y == 0)
		return (-1);
	return (1);
}

int			res_check_err(char *line_res)
{
	if (num_count(line_res) != 2)
		return (-1);
	if (min_max_res(line_res) == -1)
		return (-1);
	return (1);
}
