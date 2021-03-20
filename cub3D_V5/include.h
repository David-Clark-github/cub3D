/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:30:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/20 12:31:32 by dclark           ###   ########.fr       */
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

# define SPACE 0,200,200,200
# define EMPTY 0,255,255,255
# define WALL 0,125,125,125
# define SPRITE 0,0,255,0
# define CARA 0,255,0,0

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

typedef struct	s_map_err {
	int		x_max;
	int		y_max;
	int		player;
	char	**map;
}				t_map_err;

typedef struct	s_element_error {
	int			res;
	int			north;
	int			south;
	int			east;
	int			west;
	int			sprite;
	int			ceil;
	int			floor;
	int			map;
	t_map_err	map_err;
}				t_elem_err;

int		error_cub_master(t_elem_err *elem_err, t_elem_l *elem_l, char **line_s);
int		check_error(t_elem_err *elem_err);

void	print_elem_err(t_elem_err *elem_err);

int		floor_ceil_err(char *line);
int		res_err(char *line);
int		path_error(char *line);
int		map_error(t_map_err *map_err, char **map);
void	map_max(t_map_err *s_map, char **map);
void	create_map(t_map_err *s_map, char **map);
int		cara_voisin(t_map_err *s_map);
int		check_map(char **map);
int		one_player_map(char **map);
int		empty_line_map(char **map);
int		caract_map(char **map);

/*
** ---- PARSING ----
*/

typedef struct	s_resolution {
	int	x;
	int	y;
}				t_res;

typedef struct	s_color {
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_texture {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}				t_text;

typedef struct	s_pars {
	t_res		res;
	t_text		north;
	t_text		south;
	t_text		east;
	t_text		west;
	t_text		sprite;
	t_color		floor;
	t_color		ceil;
}				t_pars;


/*
** ---- UTILS ----
*/

int		check_ac_av(int ac, char **av);
char	**file_line_gnl(char *av);
void	print_split_l(char **line_s);

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_map {
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef	struct	s_player {
	double	pos_x;
	double	pos_y;
	double	pdx;
	double	pdy;
	double	pa;
}				t_ply;

typedef struct	s_image_alpha {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}				t_img_a;

void	draw_square(t_img_a *img_a, int x, int y, int size, int color);
void	my_put_pixel(t_img_a *img_a, int x, int y, int color);
void	map_to_image(t_img_a *img_a, t_map *map);
int		create_trgb(int t, int r, int g, int b);

/*
**	---- MASTER_DATA ----
*/

typedef struct	s_data {
	char		**raw_cub_l;
	t_elem_l	elem_l;
	t_elem_err	elem_err;
	t_map_err	map_err;
	t_win		win;
	t_img_a		img_a;
	t_res		res;
	t_north		north;
	t_south		south;
	t_east		east;
	t_west		west;
	t_sprite	sprite;
	t_floor		floor;
	t_ceil		ceil;
	t_map		map;
}				t_data;

void	parsing_master(t_data *data);
void	get_res(char *line, t_res *res);
#endif
