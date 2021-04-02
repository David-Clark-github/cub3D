#ifndef INCLUDE_H
# define INCLUDE_H

#include "include.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

# define MAP_W 8
# define MAP_H 8
# define FLOOR 0,100,100,100
# define CEIL 0,135,206,235
# define N_C 0,0,0,255
# define S_C 0,0,255,0
# define E_C 0,255,0,0
# define W_C 0,255,255,0
# define TXT_H 64
# define TXT_W 64
# define WIN_W 1000
# define WIN_H 1000
# define SP_NUM	2

# define PI 3.1415926535

int	map[MAP_H][MAP_W] = 
{
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,2,0,0,1,1,1},
	{1,0,1,0,0,0,0,1},
	{1,1,2,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1},
};

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_texture {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}				t_tx;

typedef struct	s_sprite {
	int	x;
	int	y;
}				t_sp;

typedef struct	s_ray {
	double	pa;				//cercle de 0 a 2 PI
	double	pos_x;			//position x du joueur
	double	pos_y;			//position y du joueur
	double	dir_x;			//vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double	dir_y;			//vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double	plan_x;			// vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double	plan_y;			// vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double	ray_dir_x;		//vecteur de direction du rayon
	double	ray_dir_y;		//vecteur de direction du rayon
	double	camera_x;		// point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		map_x;			//coordonée x du carré dans lequel est pos
	int		map_y;			//coordonée y du carré dans lequel est pos
	double	time;			//time of current frame
	double	old_time;		//time of previous frame
	double	move_spd;		//constant value in sqaure/second
	double	rot_spd;		//constant value in radians/second
	double	side_dist_x;	//distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	side_dist_y;	//distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	delta_dist_x;	//distance que rayon parcours entre chaque point d'intersection vertical
	double	delta_dist_y;	//distance que le rayon parcours entre chaque point d'intersection horizontal
	int		step_x;			// -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		step_y;			// -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit;			// 1 si un mur a ete touché, 0 sinon
	int		side;			// 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double	perpwalldist;	//distance du joueur au mur
	int		lineheight;		//hauteur de la ligne a dessiner
	int		drawstart;		//position de debut ou il faut dessiner
	int		drawend;		// position de fin ou il faut dessiner
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	double	zbuffer[WIN_H];
	int		sp_order[SP_NUM];
	double	sp_dist[SP_NUM];
	double	sp_x;
	double	sp_y;
	double	invdet;
	double	transformx;
	double	transformy;
	int		sp_screenx;
	int		sp_height;
	int		sp_width;
	int		drawstart_x;
	int		drawstart_y;
	int		drawend_x;
	int		drawend_y;
	t_img	img;
	t_win	win;
	t_tx	txt[5];
	t_sp	sp[SP_NUM];
}				t_ray;


void	draw_line();
void	darw_square();
void	algo(t_ray *ray);
void	init_image(t_img *img, int width, int height, int floor, int ceil);
int		move(int keycode, void *param);
#endif
