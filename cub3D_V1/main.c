#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "include.h"

int main(void)
{
	t_win win;
	t_player player;

	player.posx = WIDTH/2;
	player.posy = HEIGHT/2;
	init_window(&win);
	mlx_hook(win.win_ptr, 2, (1L<<0), dispatch, &win);
	mlx_loop(win.mlx_ptr);
}
