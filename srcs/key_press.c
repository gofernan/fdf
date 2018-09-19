#include "../include/fdf.h"

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
		{
			pdata->scaling /= 2.0;
		}
	}
	else if (keycode == 91)
	{
		pdata->rot_x += 5;
		pdata->rot_radx = pdata->rot_x * M_PI / 180;
	}
	else if (keycode == 84)
	{
		pdata->rot_x -= 5;
		pdata->rot_radx = pdata->rot_x * M_PI / 180;
	}
	else if (keycode == 86)
	{
		pdata->rot_y += 5;
		pdata->rot_rady = pdata->rot_y * M_PI / 180;
	}
	else if (keycode == 88)
	{
		pdata->rot_y -= 5;
		pdata->rot_rady = pdata->rot_y * M_PI / 180;
	}
	else if (keycode == 89)
	{
		pdata->rot_z += 5;
		pdata->rot_radz = pdata->rot_z * M_PI / 180;
	}
	else if (keycode == 85)
	{
		pdata->rot_z -= 5;
		pdata->rot_radz = pdata->rot_z * M_PI / 180;
	}
	else if (keycode == 18)
	{
		pdata->rot_x = -30;
		pdata->rot_radx = pdata->rot_x * M_PI / 180;
		pdata->rot_z = 45;
		pdata->rot_radz = pdata->rot_z * M_PI / 180;
	}
	else if (keycode == 49)
		init_start(pdata);
	else if (keycode == 123)
		pdata->move_x += 10;
	else if (keycode == 124)
		pdata->move_x -= 10;
	else if (keycode == 125)
		pdata->move_y -= 10;
	else if (keycode == 126)
		pdata->move_y += 10;
	else
		pdata->action = 0;
	//else if (keycode == 8)
	//	pdata->clear = 1;
	return (0);
}
