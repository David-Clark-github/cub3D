/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:25:28 by dclark            #+#    #+#             */
/*   Updated: 2021/04/10 14:47:22 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	move(int keycode, void *param)
{
	t_data *data;

	data = param;
	if (keycode == 65307)
		ft_error("Fin du programme", 0, data);
	return (1);
}
