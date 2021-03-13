/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:54:09 by user42            #+#    #+#             */
/*   Updated: 2021/03/13 14:06:13 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	res_pars(char *line, t_pars *pars)
{
	int	i;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	pars->res.x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	pars->res.y = ft_atoi(&line[i]);
}
