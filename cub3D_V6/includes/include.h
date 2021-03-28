/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:16:55 by dclark            #+#    #+#             */
/*   Updated: 2021/03/28 12:56:28 by dclark           ###   ########.fr       */
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

typedef struct	s_png {
	double	pa;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
}				t_png;

typedef struct	s_raycasting {
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	camerax;
	int		mapx;
	int		mapy;
	double	time;
	double	old_time;
	double	mv_spd;
	double	rot_spd;
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
	int		x;
}				t_ray;

typedef struct	s_texture {

}				t_tex;

typedef struct	s_sprite {

}				t_sp;

typedef struct	s_data {

}				t_data;
