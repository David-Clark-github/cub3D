/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:16:55 by dclark            #+#    #+#             */
/*   Updated: 2021/04/03 16:05:23 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_window {
	void	*mlx;
	void	*win;
}

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
	char	**map;
	int		map_h;
	int		map_w;
	int		sp_num;
}

typedef struct	s_raycasting {
	double	dirx;
	double	diry;
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
}				t_tex;

typedef struct	s_sprite {
	double	posx;
	double	posy;
}				t_sp;

typedef struct	s_data {
	t_tex	text[5];
	t_sp	*sp;
	t_ply	ply;	
}				t_data;
