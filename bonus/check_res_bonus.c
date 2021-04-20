/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:38:43 by dclark            #+#    #+#             */
/*   Updated: 2021/04/20 15:07:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	n_number(char *line)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (line[i] == 'R')
		++i;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			++num;
			while (ft_isdigit(line[i]))
				i++;
		}
		else
			i++;
	}
	if (num != 2)
		ft_error("Le nombre d'éléments de res est incorrect", 1, 0);
}

static void	min_max(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]) && line[i] != '-')
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La largeur de la fenetre est inferieur a 1", 1, 0);
	if (ft_atoi(&line[i]) > INT_MAX)
		ft_error("La largeur est superieur a un int", 1, 0);
	while (ft_isdigit(line[i]) || line[i] == '-')
		++i;
	while (line[i] && !ft_isdigit(line[i]) && line[i] != '-')
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La hauteur de la fenetre est inferieur a 1", 1, 0);
	if (ft_atoi(&line[i]) > INT_MAX)
		ft_error("La hauteur est superieur a un int", 1, 0);
}

static void	only_digit(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'R')
		++i;
	while (line[i])
		if (ft_isspace(line[i]) || ft_isdigit(line[i]))
			i++;
		else
			ft_error("Une erreur dans l'élément RES", 1, 0);
}

void		check_res(char *line)
{
	n_number(line);
	min_max(line);
	only_digit(line);
}
