/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:41:56 by dclark            #+#    #+#             */
/*   Updated: 2021/03/21 13:42:36 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	backward(t_data *data)
{
		data->player.pos_x -= data->player.pdx;
		data->player.pos_y -= data->player.pdy;
}
