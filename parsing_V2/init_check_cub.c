/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:26:53 by dclark            #+#    #+#             */
/*   Updated: 2021/02/22 11:40:45 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_check_cub(t_check_cub *check_cub)
{
	check_cub->resolution = 0;
	check_cub->north = 0;
	check_cub->south = 0;
	check_cub->west = 0;
	check_cub->east = 0;
	check_cub->sprit = 0;
	check_cub->ceiling = 0;
	check_cub->map = 0;
}
