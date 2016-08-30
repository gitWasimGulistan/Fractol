#include "../includes/fractol.h"
#include <stdio.h>

int			mouse_hook(int keycode, int x, int y, t_env *e)
{
	double	x1;
	double	y1;

	x1 = scale_x(e, x);
	y1 = scale_y(e, y);
	if (keycode == MOUSE_CLIC_L || keycode == MOUSE_WHEEL_DOWN)
	{
		e->zoom_x += 1.0;
		e->zoom_y += 1.0;
		e->x1 = x1 - (e->x2 - e->x1) / 4;
		e->x2 = x1 + (e->x2 - e->x1) / 4;
		e->y1 = y1 - (e->y2 - e->y1) / 4;
		e->y2 = y1 + (e->y2 - e->y1) / 4;
		e->i_max *= 2;
	}
	else if (keycode == MOUSE_CLIC_R || keycode == MOUSE_WHEEL_UP)
	{
		e->zoom_x -= 1.0;
		e->zoom_y -= 1.0;
		e->x1 = x1 - (e->x2 - e->x1);
		e->x2 = x1 + (e->x2 - e->x1);
		e->y1 = y1 - (e->y2 - e->y1);
		e->y2 = y1 + (e->y2 - e->y1);
		e->i_max /= 2;
	}
	expose_hook(e);
	return (0);
}