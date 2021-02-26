/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:53:28 by dclark            #+#    #+#             */
/*   Updated: 2021/02/26 15:14:09 by dclark           ###   ########.fr       */
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
** t_image contain all the necessary to create an image
*/

typedef struct	s_image {
	char	*addr;
	void	*img;
	int		line_l;
	int		bpp;
	int		endian;
	int		width;
	int		length;
}				t_image;

/*
** t_win contain all the necessary to create a window
*/

typedef struct	s_win {
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;

/*
** t_map have the hig
*/

typedef struct	s_map {
	int		x_max;
	int		y_max;
	int		map_st;
	int		player_pos[2];
	int		plyer_dir;
	char	**map;
}				t_map;

/*
** Set all elements of s_check_cub to 0
*/

void	init_check_cub(t_check_cub *check_cub);


char	*file_line(int fd);

/*
** check the .cub file before doing the parsing
*/

int		check_resolution(char *line);
int		check_floor_ceiling(char *line);
int		check_path(char *line);
void	map_max(t_map *map, char **s_line);
void	map_creation(t_map *map, char **s_line);
void	create_map(t_map *map, char **s_line);
