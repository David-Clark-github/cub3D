/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:18:48 by dclark            #+#    #+#             */
/*   Updated: 2021/02/17 15:32:21 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#define PI		3.141592653589793
#define WIDTH	1280
#define HEIGHT	720
#define TITLE	"cub3D_V1"
#define ESC		53
#define P		35	//touche p
#define LEFT	123	//flèche gauche
#define RIGHT	124	//flèche droite
#define UP		126	//flèche haut
#define DOWN	125	//flèche bas

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_img;

typedef struct	s_win {
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;

	t_img	*img;
}				t_win;

typedef struct	s_player {
	float	posx;
	float	posy;
	float	pdx;
	float	pdy;
	float	pa;
}				t_player;

void	init_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, TITLE);
	win->img = malloc(sizeof(t_img));
	win->img->img = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->img->addr = mlx_get_data_addr(win->img->img, &win->img->bpp, &win->img->line_l, &win->img->endian);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	close(void)
{
	exit(0);
}

void	erase_frame_content(t_win *win)
{
	int		n;

	n = 4 * WIDTH * HEIGHT;
	while (--n >= 0)
		win->img->addr[n] = create_trgb(0, 255, 0, 0);
}

void	mlx_my_put_pxl(t_img *img, int x, int y, int color)
{
	char	*pixel;
	pixel = img->addr + (y * img->line_l + x * (img->bpp/8));
	*(int*)pixel = color;

}

int	dispatch(int keycode, void *param)
{
	t_win	*win;
	static float px = (WIDTH/2);
	static float py = (HEIGHT/2);
	static float pa = 0.0;
	static float pdx = 0.0;
	static float pdy = 0.0;

	win = param;
	pdx = cosf(pa) * 2.0;
	pdy = sinf(pa) * 2.0;
	printf("pdx = %f\n", pdx);
	printf("pdy = %f\n", pdy);
	if (keycode == ESC)
		close();
	if (keycode == UP)
	{
		px += pdx;
		py += pdy;	
	}
	if (keycode == DOWN)
	{
		px -= pdx;
		py -= pdy;
	}
	if (keycode == LEFT)
	{
		pa -= 0.1;
		if (pa < 0)
			pa += (2.0 * PI);
		pdx = cosf(pa) * 2.0;
		pdy = sinf(pa) * 2.0;
	}
	if (keycode == RIGHT)
	{
		pa += 0.1;
		if (pa > (2.0 * PI))
			pa -= (2.0 * PI);
		pdx = cosf(pa) * 2.0;
		pdy = sinf(pa) * 2.0;
	}
	erase_frame_content(win);
	mlx_my_put_pxl(win->img, (int)px, (int)py, create_trgb(0, 255, 255, 255));
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	return (1);
}

