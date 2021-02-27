/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:53:28 by dclark            #+#    #+#             */
/*   Updated: 2021/02/27 12:02:18 by dclark           ###   ########.fr       */
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

/*
***************** Check Error *****************
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

void	init_check_cub(t_check_cub *check_cub);
int		check_resolution(char *line);
int		check_floor_ceiling(char *line);
int		check_path(char *line, t_win *win, t_img *img);

/*
** file line return a single line from a file
** 
** Then I create a square map with space when empty
** 00..
** 0100
** 0110
** 0000
** The dot are spaces
*/

char	*file_line(int fd);
void	map_max(t_map *map, char **s_line);
void	create_map(t_map *map, char **s_line);


/*
** check the .cub file before doing the parsing
*/

int	check_cub(t_check_cub *cub);
/*
***************** Parsing *****************
*/

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
** Struct for the map
** x_max and y_max are the width and height of the map
** map_st is the line where the map begin in the split_line value (look at the main)
** player_pos represent the postion of the player x = pos[0], y = pos[1]
** player_dir is the direction that the player is looking
** 	1:NO	2:ES	3:SO	4:WE
** map is the map created by create_map with 0 at the last line to finish it
*/

typedef struct	s_map {
	int		x_max;
	int		y_max;
	int		map_st;
	int		player_pos[2];
	int		player_dir;
	char	**map;
}				t_map;
