/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_split_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:31:15 by dclark            #+#    #+#             */
/*   Updated: 2021/03/01 15:33:01 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_split_l(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
		printf("%s\n", split_line[i]);
		i++;
	}
}
