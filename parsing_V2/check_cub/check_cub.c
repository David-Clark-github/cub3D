/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 10:38:16 by dclark            #+#    #+#             */
/*   Updated: 2021/02/27 10:50:58 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

/*
** Return 1 if all elements are OK
** Return 0 otherwise
*/

int	check_cub(t_check_cub *cub)
{
	int	res;

	res = 1;
	if (cub->resolution != 1)
		res = 0;
	if (cub->north != 1)
		res = 0;
	if (cub->south != 1)
		res = 0;
	if (cub->west = 0)
		res = 0;
	if (cub->east != 1)
		res = 0;
	if (cub->sprit != 1)
		res = 0;
	if (cub->floor != 1)
		res = 0;
	if (cub->ceiling != 1)
		res = 0;
	if (cub->map != 1)
		res = 0;
	return (res);
}
