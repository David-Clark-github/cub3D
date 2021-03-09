/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_check_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:28:21 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 12:42:11 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	num_c(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
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

static int	comma_c(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			res++;
		i++;
	}
	return (res);
}

static int	boundaries(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == ',')
			i++;
		if (ft_atoi(&str[i]) < 0 || ft_atoi(&str[i]) > 255)
			return (-1);
		while (ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}
	return (1);
}

static int	format(char *str)
{
	int	i;

	i = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == ',')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == ',')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] != '\0')
		return (-1);
	return (1);
}

int			floor_check_err(char *line)
{
	if (format(line) == -1)
		return (-1);
	if (comma_c(line) != 2)
		return (-1);
	if (num_c(line) != 3)
		return (-1);
	if (boundaries(line) == -1)
		return (-1);
	return (1);
}
