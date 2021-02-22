/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:53:28 by dclark            #+#    #+#             */
/*   Updated: 2021/02/22 14:23:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"
#include "libft.h"


/*
** 01 = OK
** 00 = Not check yet
** -1 = An error occured
** the objectif is to simply check the file .cub
** the result of checking each element is store in this structure
*/

typedef struct	s_check_cub {
	int	resolution;
	int	north;
	int	south;
	int	west;
	int	east;
	int	sprit;
	int	floor;
	int	ceiling;
	int	map;
}				t_check_cub;

/*
** Set all elements of s_check_cub to 0
*/

void	init_check_cub(t_check_cub *check_cub);


char	*file_line(int fd);
int		check_resolution(char *line);
int		check_floor(char *line);
