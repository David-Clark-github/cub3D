/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:40:38 by dclark            #+#    #+#             */
/*   Updated: 2021/04/06 16:30:45 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_id_l(t_id_l *id_l)
{
	printf("res = %d\n", id_l->res);
	printf("north = %d\n", id_l->north);
	printf("south = %d\n", id_l->south);
	printf("east = %d\n", id_l->east);
	printf("west = %d\n", id_l->west);
	printf("sprite = %d\n", id_l->sprite);
	printf("floor = %d\n", id_l->floor);
	printf("ceil = %d\n", id_l->ceil);
	printf("map = %d\n", id_l->map);
}

void	print_data(t_data *data)
{
	ft_print_split(data->raw_cub);	
	print_id_l(&data->id_l);
}
