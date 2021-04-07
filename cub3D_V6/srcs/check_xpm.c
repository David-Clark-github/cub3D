/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:31:29 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 11:51:20 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	xpm_file(char *line)
{
	if (ft_strncmp(&line[ft_strlen(line) - 4], ".xpm", 4) != 0)
		ft_error("La texture n'est pas un fichier xpm", 1, 0);
}

void		check_xpm(char *line)
{
	xpm_file(line);
}
