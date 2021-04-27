/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:38:43 by dclark            #+#    #+#             */
/*   Updated: 2021/04/27 15:38:36 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	n_number(char *line, t_data *data)
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
		ft_error("Le nombre d'éléments de res est incorrect", 1, data);
}

static void	min_max(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]) && line[i] != '-')
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La largeur de la fenetre est trop petite", 1, data);
	if (ft_atoi(&line[i]) > INT_MAX)
		ft_error("La largeur est superieur a un int", 1, data);
	while (ft_isdigit(line[i]) || line[i] == '-')
		++i;
	while (line[i] && !ft_isdigit(line[i]) && line[i] != '-')
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La hauteur de la fenetre est trop petite", 1, data);
	if (ft_atoi(&line[i]) > INT_MAX)
		ft_error("La hauteur est superieur a un int", 1, data);
}

static void	only_digit(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == 'R')
		++i;
	while (line[i])
		if (ft_isspace(line[i]) || ft_isdigit(line[i]))
			i++;
		else
			ft_error("Une erreur dans l'élément RES", 1, data);
}

void		check_res(char *line, t_data *data)
{
	n_number(line, data);
	min_max(line, data);
	only_digit(line, data);
}
