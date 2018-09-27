#include "../include/fdf.h"

void		reset_values(t_data *pdata)
{
	if (!pdata->reset)
	{
		init_start(pdata);
		pdata->reset = 1;
	}
}

int			close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			key_press(int keycode, t_data *pdata)
{
	pdata->action = 1;
	if (keycode == 53)
		close_window(pdata);
	else if (keycode == 69)
	{
		if (pdata->scaling < 32.0)
			pdata->scaling += 0.1;
	}
	else if (keycode == 78)
	{
		if (pdata->scaling >= 0.0625)
			pdata->scaling /= 2.0;
	}
	else if (keycode == 91)
		pdata->rot_x += 5;
	else if (keycode == 84)
		pdata->rot_x -= 5;
	else if (keycode == 86)
		pdata->rot_y += 5;
	else if (keycode == 88)
		pdata->rot_y -= 5;
	else if (keycode == 92)
		pdata->rot_z += 5;
	else if (keycode == 89)
		pdata->rot_z -= 5;
	else if (keycode == 15)
		reset_values(pdata);
	else if (keycode == 34)
		pdata->info = pdata->info == 1 ? 0 : 1;
	else if (keycode == 49)
		pdata->proj = pdata->proj == 0 ? 1 : 0;
	else if (keycode == 123)
		pdata->move_x += 20;
	else if (keycode == 124)
		pdata->move_x -= 20;
	else if (keycode == 125)
		pdata->move_y -= 20;
	else if (keycode == 126)
		pdata->move_y += 20;
	else if (keycode == 18)
		pdata->xtile += 1;
	else if (keycode == 19)
		pdata->xtile -= 1;
	else if (keycode == 20)
		pdata->ytile += 1;
	else if (keycode == 21)
		pdata->ytile -= 1;
	else if (keycode == 22)
		pdata->ztile += 1;
	else if (keycode == 23)
		pdata->ztile -= 1;
	else
		pdata->action = 0;
	return (0);
}
