/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:21:51 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 15:23:29 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_ray(t_ray *ray)
{
	if (ray->zbuffer != NULL)
		free(ray->zbuffer);
	if (ray->sp_order != NULL)
		free(ray->sp_order);
	if (ray->sp_dist != NULL)
		free(ray->sp_dist);
}
