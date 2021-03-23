#ifndef INCLUDE_H
 #define INCLUDE_H

#include "include.h"

# define MAP_W 6
# define MAP_H 6


int	map[MAP_H][MAP_W] = 
{
	{1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 1},
	{1, 0, 1, 0, 0, 1},
	{1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1},
}

typedef struct	s_ray {
	double	pos_x;			//position x du joueur
	double	pos_y;			//position y du joueur
	double	dir_x;			//vecteur de direction
	double	dir_y;			//vecteur de direction
	double	ray_dir_x;		//vecteur de direction du rayon
	double	ray_dir_y;		//vecteur de direction du rayon
	int		map_x;			//coordonée x du carré dans lequel est pos
	int		map_y;			//coordonée y du carré dans lequel est pos
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
	int		x;				// permet de parcourir tous les rayons
}				t_ray;

void	draw_line();
void	darw_square();

#endif
