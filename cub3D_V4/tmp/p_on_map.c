#include "include.h"

#define PI		3.141592653589793
#define TITLE	"cub3D"
#define ESC		0xff1b
#define P		112
#define	LEFT	65361
#define	UP		65362
#define	RIGHT	65363
#define	DOWN	65364

void	close(void)
{
	exit(EXIT_SUCCESS);
}

int	dispatch(int keycode, void *param)
{
	t_pars	*pars;
	static float	px = (pars->res.x/2);
	static float	py = (pars->res.y/2);
	static float	pa = 1.0;
	static float	pdx = 0.0;
	static float	pdy = 0.0;

	pars = param;
	pdx = cosf(pa) * 2.0;
	pdy = sinf(pa) * 2.0;
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
	erase_frame()
}

