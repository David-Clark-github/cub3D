#include <mlx.h>
#include <stdio.h>

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_img;

int main(void)
{
	t_win	win;
	//t_img	img;

	win.mlx = mlx_init();
	printf("win = %p\n", win.mlx);
}
