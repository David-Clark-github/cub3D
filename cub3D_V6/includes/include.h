/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:16:55 by dclark            #+#    #+#             */
/*   Updated: 2021/04/05 15:00:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

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
}				t_win;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		hieght;
	int		endian;
}				t_img;

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

typedef struct	s_mapou {
	int		**map;
	int		map_h;
	int		map_w;
	int		sp_num;
}				t_mapou;

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
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wall_x;
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
	t_id_l	id_l;
	t_img	img;
	t_win	win;
	t_ply	ply;
	t_ray	ray;
	t_text	text[5];
	t_sp	*sp;
}				t_data;

void	ft_error(char *message, int error, t_data *data);
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
#endif
