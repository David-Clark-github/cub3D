/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:50:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/04 15:49:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*file_line(int fd);
void	print_split_l(char **sp_line);

/*
****************	Identifier_line_cub		****************
*/

typedef struct	s_element_line {
	int	res;
	int	north;
	int	south;
	int	west;
	int	east;
	int	sprit;
	int	floor;
	int	ceil;
	int	map;
}				t_elem_l;

void	init_elem_line(t_elem_l *elem_l);
int    identify_lines(char **sp_line, t_elem_l *elem_l);
void    print_elem_l(t_elem_l *elem_l);
void	res_line(char **sp_line, t_elem_l *elem_l);
void	north_line(char **sp_line, t_elem_l *elem_l);
void	south_line(char **sp_line, t_elem_l *elem_l);
void	west_line(char **sp_line, t_elem_l *elem_l);
void	east_line(char **sp_line, t_elem_l *elem_l);
void	sprit_line(char **sp_line, t_elem_l *elem_l);
void	floor_line(char **sp_line, t_elem_l *elem_l);
void	ceil_line(char **sp_line, t_elem_l *elem_l);
void	map_line(char **sp_line, t_elem_l *elem_l);
int		check_exist(t_elem_l *elem_l);

/*
****************	Check_error				****************
*/

typedef struct	s_element_check {
	int	res;
	int	north;
	int	south;
	int	west;
	int	east;
	int	sprit;
	int	floor;
	int	ceil;
	int	map;
}				t_elem_c;
int		check_error(char **line_s, t_elem_l *elem_l);
void	print_elem_check(t_elem_c *elem_check);
void	init_elem_check_1(t_elem_c *elem_check, t_elem_l *el_l, char **line_s);
int		res_check_err(char *line_res);
int		floor_check_err(char *line_res);
int		ceiling_check_err(char *line_res);

typedef struct	s_map_error {
	int		y_max;
	int		x_max;
	int		player;
	char	**map;
}				t_map_err;

int		map_check_err(t_map_err *map_err, char **line_s, int map_st);
int		check_map(t_map_err *map);
int		one_player_map(char **map);
int		empty_line_map(char **map);
#endif
