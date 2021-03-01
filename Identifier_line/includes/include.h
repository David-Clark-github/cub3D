/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:50:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/01 15:42:50 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_element_line {
	int	res;
	int	north;
	int	south;
	int	east;
	int	west;
	int	floor;
	int	ceiling;
	int	map;
}				t_el_l;

char	*file_line(int fd);
void	print_split_l(char **split_line);
#endif
