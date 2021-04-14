/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:16:55 by dclark            #+#    #+#             */
/*   Updated: 2021/04/14 11:07:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define ESC		65307
# define RT_LEFT	65361
# define RT_RIGHT	65363
# define FORWARD	122
# define BACKWARD	115
# define CRABE_L	113
# define CRABE_R	100

typedef struct	s_id_line {
	int	res;
	int	north;
	int	south;
	int	east;
	int	west;
	int	sprite;
	int	floor;
	int	ceil;
	int	map;
}				t_id_l;

typedef struct	s_window {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
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

typedef struct	s_mapou {
	char	**map;
	int		map_h;
	int		map_w;
	int		sp_num;
}				t_mapou;

typedef struct	s_floor {
	int	r;
	int	g;
	int	b;
	int	color;
}				t_floor;

typedef struct	s_ceil {
	int	r;
	int	g;
	int	b;
	int	color;
}				t_ceil;

typedef struct	s_player {
	double	pa;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	rot_spd;
	double	mv_spd;
}				t_ply;

typedef struct	s_raycasting {
	double	rdirx;
	double	rdiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	time;
	double	old_time;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwd;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	int		x;
	double	*zbuffer;
	int		*sp_order;
	double	*sp_dist;
	double	sp_x;
	double	sp_y;
	double	invdet;
	double	transformx;
	double	transformy;
	int		sp_screenx;
	int		sp_height;
	int		sp_width;
	int		drawst_x;
	int		drawst_y;
	int		drawend_x;
	int		drawend_y;
}				t_ray;

typedef struct	s_texture {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}				t_text;

typedef struct	s_sprite {
	double	posx;
	double	posy;
}				t_sp;

typedef struct	s_data {
	char	**raw_cub;
	t_mapou	map;
	t_id_l	id_l;
	t_win	win;
	t_img	img;
	t_floor	floor;
	t_ceil	ceil;
	t_ply	ply;
	t_ray	ray;
	t_text	text[5];
	t_sp	*sp;
}				t_data;

//void	print_data(t_data *data);

void	ft_error(char *message, int error, t_data *data);
void	ft_save(t_data *data);
void	ft_empty_data(t_data *data);
void	free_win(t_win *win);
void	free_img(t_img *img, t_win *win);
void	free_map(t_mapou *map);
void	free_ray(t_ray *ray);
void	free_text(t_data *data);
void	init_data(t_data *data);
void	init_id_l(t_id_l *id_l);
void	init_img(t_img *img);
void	init_win(t_win *win);
void	init_map(t_mapou* map);
void	init_ply(t_ply *ply);
void	init_ray(t_ray *ray);
void	init_text(t_data *data);
void	check_ac_av(int ac, char **av);
char	**file_line_gnl(char *av);
void	id_line_master(t_data *data);
int		id_res(char **av);
int		id_north(char **av);
int		id_south(char **av);
int		id_east(char **av);
int		id_west(char **av);
int		id_sprite(char **av);
int		id_floor(char **av);
int		id_ceil(char **av);
int		id_map(char **av);
void	check_master(t_data *data);
void	check_res(char *res);
void	check_north(char *north);
void	check_south(char *south);
void	check_east(char *east);
void	check_west(char *west);
void	check_xpm(char *line);
void	check_sprite(char *sprite);
void	check_floor_ceil(char *line);
void	check_map1(char **map, t_data *data);
void	check_map2(char **map, t_data *data);
void	parsing_master(t_data *data);
void	pars_res(t_data *data, char *line);
void	pars_xpm(t_data *data, int i, char *line);
void	pars_sprite(char **map, t_data *data);
void	pars_ply(char **map, t_data *data);
void	pars_img(t_img *img, t_win *win, t_data *data);
void	pars_floor(t_data *data, char *line);
void	pars_ceil(t_data *data, char *line);
int		trgb(int t, int r, int g, int b);
void	my_put_pixel(t_img *img, int x, int y, int color);
int		index_color(int x, int y, t_text *text);
void	ceil_floor_to_img(t_data *data);
void	algo(t_data *data);
void	exec(t_data *data);
void	draw_text_line(t_text *text, int x, t_ray *ray, t_data *data);
int		move(int keycode, void *param);
void	rotate_left(t_ply *ply);
void	rotate_right(t_ply *ply);
void	forward(t_ply *ply, t_mapou *map);
void	backward(t_ply *ply, t_mapou *map);
void	crabe_left(t_ply *ply, char **map);
void	crabe_right(t_ply *ply, char **map);
void	algo_sprite(t_data *data, t_ray *ray, t_ply *ply);
#endif
