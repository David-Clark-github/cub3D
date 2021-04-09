#include "include.h"

void	pars_img(t_img *img, t_win *win)
{
	img->img = mlx_new_image(win->mlx, win->width, win->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_l, &img->endian);
}
