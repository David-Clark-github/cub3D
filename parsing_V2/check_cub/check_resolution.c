/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:44:29 by dclark            #+#    #+#             */
/*   Updated: 2021/02/22 14:47:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_resolution(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'R')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_atoi(&line[i]) < 1)
		return (-1);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_atoi(&line[i]) < 1)
		return (-1);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}
