/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:22:37 by dclark            #+#    #+#             */
/*   Updated: 2021/02/25 10:33:35 by dclark           ###   ########.fr       */
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
		if (ft_isdigit(line[i]))
		{
			res++;
			while (ft_isdigit(line[i]))
				i++;
		}
		else
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

static int max_min_rgb(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			if (ft_atoi(&line[i]) > 255)
				return (-1);
			while (ft_isdigit(line[i]))
				i++;
		}
		else
			i++;
	}
	return (1);
}

static int	check_num_neg(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

static int	format(char *line)
{
	int	i;
	int	count;

	i = 1;
	count = 3;
	while (count-- > 0)
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (ft_atoi(&line[i]) < 0 || ft_atoi(&line[i]) > 255)
			return (-1);
		while (ft_isdigit(line[i]))
			i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == ',' && count > 0)
			i++;
		else if (count == 0 && line[i] != ',')
			i += 0;
		else
			return (-1);
	}
	if (line[i] != '\0')
		return (-1);
	return (1);
}

/*
** int i start at 1 because we know that the fisrt caracter is the letter 'F'
*/

int	check_floor_ceiling(char *line)
{
	if (count_number(line) == 3 && count_comma(line) == 2 && check_num_neg(line) == 1)
		if (format(line) == 1)
			return (1);
	return (-1);
}
