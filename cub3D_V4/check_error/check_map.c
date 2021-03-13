/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:24:39 by dclark            #+#    #+#             */
/*   Updated: 2021/03/12 14:14:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_err.h"

int	check_map(char	**map)
{

	if (one_player_map(map) == -1)
	{
//		printf("Il y plus de 1 ou aucun joueur sur la map\n");
		return (-1);
	}	
	if (empty_line_map(map) == -1)
	{
//		printf("La map est divise\n");
		return (-1);
	}
	if (caract_map(map) == -1)
	{
//		printf("Format incorect de la map");
		return (-1);
	}
	return (1);
}
