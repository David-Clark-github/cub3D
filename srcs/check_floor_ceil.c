/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceil.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:28:21 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 13:32:14 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	num_c(char *str)
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
	if (res != 3)
		ft_error("Il y a trop de couleur dans la ligne", 1, 0);
}

static void	comma_c(char *str)
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
	if (res != 2)
		ft_error("Le nombre de virgule est incorrect", 1, 0);
}

static void	boundaries(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == ',')
			i++;
		if (ft_atoi(&str[i]) < 0 || ft_atoi(&str[i]) > 255)
			ft_error("La couleur est hors limite", 1, 0);
		while (ft_isdigit(str[i]) || str[i] == '-')
			i++;
	}
}

static void	format(char *str)
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
	if (str[i] != '\0')
		ft_error("Le format pour les couleurs est incorect", 1, 0);
}

void		check_floor_ceil(char *line)
{
	comma_c(line);
	num_c(line);
	boundaries(line);
	format(line);
}
