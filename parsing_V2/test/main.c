#include <stdio.h>
#include "mlx.h"

typedef struct	s_window {
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	int		width;
	int		height;
}				t_img;

int main(int ac, char **av)
{
	(void)ac;
	void	*xpm_file;
	t_win	win;
	t_img	img;

	win.mlx_ptr = mlx_init();
	//win.win_ptr = mlx_new_window(win.mlx_ptr, 500, 500, "Test");
	img.img = mlx_new_image(win.mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(&img.img, &img.bpp, &img.line_l, &img.endian);
	xpm_file = mlx_xpm_file_to_image(win.mlx_ptr, av[1], &img.width, &img.height);
	if (xpm_file == NULL)
		printf("Yo t NULL");
	else
		printf("xpm_file = %p\n", xpm_file);
}
