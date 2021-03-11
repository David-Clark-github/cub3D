/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:50:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/11 13:46:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "id_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	**file_line_gnl(char *av);
void	print_split_l(char **sp_line);
int		get_next_line(int fd, char **line);

/*
****************	Check_error				****************
*/

typedef struct	s_element_error {
	int	res;
	int	north;
	int	south;
	int	west;
	int	east;
	int	sprit;
	int	floor;
	int	ceil;
	int	map;
}				t_elem_err;

void	print_elem_err(t_elem_err *elem_check);

void	init_elem_err(t_elem_err *el_err, t_elem_l *el_l, char **line_s);
int		check_error(t_elem_err *el_err);

int		res_check_err(char *line_res);
int		floor_check_err(char *line_res);
int		ceiling_check_err(char *line_res);
int		path_check_error(char *line);

typedef struct	s_map_error {
	int		y_max;
	int		x_max;
	int		player;
	char	**map;
}				t_map_err;

int		map_check_err(t_map_err *map_err, char **line_s, int map_st);
int		check_map(char **map);
int		one_player_map(char **map);
int		empty_line_map(char **map);
int		caract_map(char **map);
int		cara_voisin(t_map_err *map_err);

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}				t_img;
#endif
