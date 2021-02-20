#include "include.h"
#include "mlx.h"
#include "libft.h"

int	main(void)
{
	t_win	win;
	int		m[10][7] =
	{
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 7; j++)
			win.map.maping[i][j] = m[i][j];
	/*
	win.map.maping[0][0] = 0;
	win.map.maping[0][1] = 0;
	win.map.maping[0][2] = 0;
	win.map.maping[1][0] = 0;
	win.map.maping[1][1] = 1;
	win.map.maping[1][2] = 0;
	win.map.maping[2][0] = 0;
	win.map.maping[2][1] = 0;
	win.map.maping[2][2] = 0;*/
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIDTH, HEIGHT, "cub3D_V3");
	win.img.img = mlx_new_image(win.mlx_ptr, WIDTH, HEIGHT);
	win.img.addr = mlx_get_data_addr(win.img.img, &win.img.bpp, &win.img.line_l, &win.img.endian);
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (win.map.maping[x][y] == 0)
				my_draw_square(&win.img, (x * 10), (y * 10), 10, create_color(0, 255, 255, 255));
			else
				my_draw_square(&win.img, (x * 10), (y * 10), 10, create_color(0, 255, 0, 0));
		}
	}
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img.img, 0, 0);
	mlx_loop(win.mlx_ptr);
}
