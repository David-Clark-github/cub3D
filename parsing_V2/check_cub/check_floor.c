/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:22:37 by dclark            #+#    #+#             */
/*   Updated: 2021/02/23 14:11:45 by dclark           ###   ########.fr       */
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
	printf("Hey!\n");
	while (count-- > 0)
	{
		printf("%s\n", &line[i]);
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
		else if (count == 1 && line[i] != ',')
			i += 0;
		else
			return (-1);
	}
	return (1);
}

/*
** int i start at 1 because we know that the fisrt caracter is the letter 'F'
*/

int	check_floor(char *line)
{
	int	i;
	int	num_count;
	int	comma_count;
	int	ma_mi_rgb;
	int	check_num_n;

	num_count = count_number(line);
	comma_count = count_comma(line);
	check_num_n = check_num_neg(line);
	ma_mi_rgb = max_min_rgb(line);
	printf("num_count = %d\n", num_count);
	printf("comma_count = %d\n", comma_count);
	printf("check_num_n = %d\n", check_num_n);
	printf("ma_mi_rgb = %d\n", ma_mi_rgb);
	if (num_count == 3 && comma_count == 2)
	{
		printf("il rentre :)\n");
		if (format(line) == 1)
			return (1);
		printf("il sort :/\n");
	}
	return (-1);
}
