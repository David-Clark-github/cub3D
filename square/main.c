/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:43:31 by dclark            #+#    #+#             */
/*   Updated: 2021/03/14 13:14:30 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		endian;
}				t_img;

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel(t_img *img, int x, int y, int color)
{
	char    *dst;

    dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int y_s;
	int	x_s;

	y_s = 0;
	x_s = 0;
	while (y_s < size)
	{
		while (x_s < size)
		{
			my_mlx_pixel(img, (x + x_s), (y + y_s), color);
			x_s++;
		}
		x_s = 0;
		y_s++;
	}
}

int main(void)
{
	t_win	win;
	t_img	img;
	int	win_x = 500;
	int	win_y = 1000;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win_x, win_y, "Lauranne");
	img.img = mlx_new_image(win.mlx, win_x, win_y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	draw_square(&img, 0, 0, win_x, create_trgb(0, 0, 255, 0));
	draw_square(&img, 0, win_y / 2, win_x, create_trgb(0, 0, 0, 255));
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
	mlx_loop(win.mlx);
}
