/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:36:16 by dclark            #+#    #+#             */
/*   Updated: 2021/03/13 14:39:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(char **line_s, t_elem_l *el_l, t_pars *pars)
{
	res_pars(line_s[el_l->res], pars);
	north_pars(line_s[el_l->sprite], pars);
	south_pars(line_s[el_l->sprite], pars);
	east_pars(line_s[el_l->sprite], pars);
	west_pars(line_s[el_l->sprite], pars);
	sprite_pars(line_s[el_l->sprite], pars);
	floor_pars(line_s[el_l->floor], pars);
	ceil_pars(line_s[el_l->ceil], pars);
}
