/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:53:28 by dclark            #+#    #+#             */
/*   Updated: 2021/02/26 15:14:11 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 1280
#define HEIGHT 720

typedef struct	s_plyr {
	float	pos_x;
	float	pos_y;
	float	dlt_x;
	float	dlt_y;
	float	angle;
}				t_plyr;

typedef struct	s_map {
	//int	sqr_sz = 10;
	int	wall_color;		//0, 255, 255, 255
	int	floor_color;	//0, 255, 0, 0
	int	maping[10][7];	// 0 = wall, 1 = floor
}				t_map;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	t_plyr	*plyr;
}				t_image;

typedef struct	s_win {
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;
	t_map	map;
}				t_win;

int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_draw_pixel(t_image *img, int x, int y, int color)
{
	char	*pxl;
	pxl = img->addr + (x * (img->bpp/8) + y * img->line_l);
	*(int*)pxl = color;
}

void	my_draw_square(t_image *img, int x, int y, int size, int color)
{
	int	x_start;
	int	x_finish;
	int	y_finish;
	int	size_cp;

	x_start = x;
	x_finish = x + size;
	y_finish = y + size;
	size_cp = size;
	while (y < y_finish)
	{
		while (x < x_finish)
		{
			my_draw_pixel(img, x, y, color);
			x++;
		}
		x = x_start;
		y++;
	}
}


