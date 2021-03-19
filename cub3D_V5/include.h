/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:30:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/19 14:44:52 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "mlx.h"

/*
** ---- get_next_line ----
*/

int		get_next_line(int fd, char **line);
char	*get_line(char *tmp);
char	*get_after_eol(char *tmp);
char	*ftft_strjoin(char *tmp, int tmp_sz, char *buffer, int bytes_read);
int		check_eol(char *tmp);
int		return_zero(char *tmp);

/*
** ---- ID_LINE ----
*/

typedef struct	s_element_line {
	int	res;
	int	north;
	int	south;
	int	east;
	int	west;
	int	sprite;
	int	ceil;
	int	floor;
	int	map;
}				t_elem_l;

int		id_line_master(char **line_s, t_elem_l *elem_l); // return 1 or -1

void	init_elem_line(t_elem_l *elem_l);
int		check_elem_l(t_elem_l *elem_l);

void	print_elem_l(t_elem_l *elem_l);

void	res_line(char **line_s, t_elem_l *elem_l);
void	north_line(char **sp_line, t_elem_l *elem_l);
void	south_line(char **sp_line, t_elem_l *elem_l);
void	west_line(char **sp_line, t_elem_l *elem_l);
void	east_line(char **sp_line, t_elem_l *elem_l);
void	sprit_line(char **sp_line, t_elem_l *elem_l);
void	floor_line(char **sp_line, t_elem_l *elem_l);
void	ceil_line(char **sp_line, t_elem_l *elem_l);
void	map_line(char **sp_line, t_elem_l *elem_l);

/*
** ---- CHECK_ERROR ----
*/

typedef struct	s_element_error {
	int	res;
	int	north;
	int	south;
	int	east;
	int	west;
	int	sprite;
	int	ceil;
	int	floor;
	int	map;
}				t_elem_err;

int		error_cub_master(t_elem_err *elem_err, t_elem_l *elem_l, char **line_s);
int		check_error(t_elem_err *elem_err);

void	print_elem_err(t_elem_err *elem_err);

int		floor_ceil_err(char *line);
int		res_err(char *line);
int		path_error(char *line);

/*
** ---- PARSING ----
*/

/*
** ---- UTILS ----
*/

int		check_ac_av(int ac, char **av);
char	**file_line_gnl(char *av);

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

/*
**	---- MASTER_DATA ----
*/

typedef struct	s_data {
	char		**raw_cub_l;
	t_elem_l	elem_l;
	t_elem_err	elem_err;
	t_win		win;
}				t_data;

#endif