/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av_ac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:17:18 by dclark            #+#    #+#             */
/*   Updated: 2021/04/05 12:45:57 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	ac_two(char **av)
{
	if (ft_strlen(av[1]) < 4)
		ft_error("Nom de l'argument impossible", 1, 0);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		ft_error("Nom de l'argument incorrect", 1, 0);
}

static void	ac_three(char **av)
{
	/*if (ac_two(av) == -1)
		return (-1);*/
	if (ft_strlen(av[2]) != 6)
		ft_error("L'argument n°2 est incorrect", 1, 0);
	if (ft_strncmp("--save", av[2], 6) != 0)
		ft_error("L'argument n°2 est incorrect", 1, 0);
}

void	check_ac_av(int ac, char **av)
{
	int	fd;

	if (ac < 2 || ac > 3)
		ft_error("Le nombre d'argument est incorrect", 1, 0);
	if (ac == 2)
		ac_two(av);
	if (ac == 3)
		ac_three(av);
	if ((fd = open(av[1], O_DIRECTORY)) != -1)
	{
		close(fd);
		ft_error("*.cub est un repertoir, ça marche pas x)", 1, 0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("Erreur lors de l'ouverture du *.cub", 1, 0);
}
