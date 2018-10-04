#include "../include/fdf.h"

int get_light(int start, int end, double percent)
{
    return ((int)((1 - percent) * start + percent * end));
}

int				get_gradient(float percent, int color1, int color2)
{
	int red;
	int green;
	int blue;

	red = get_light((color1 >> 16 & 0xff), (color2 >> 16 & 0xff), percent);
	green = get_light((color1 >> 8 & 0xff), (color2 >> 8 & 0xff), percent);
	blue = get_light((color1 & 0xff), (color2 & 0xff), percent);
	return ((red << 16) | (green << 8) | blue);
}

float			percent(int start, int end, int current)
{
	float percent;
	percent = (float)(current - start) / (end - start);
	return (percent);
}

int			point_color(t_data *pdata, int current, int opt)
{
	int color1;
	int color2;
	float prc;

	if (!opt)
	{
		color1 = 0x463300;
		color2 = 0xc3b180;
	}
	else
	{
		color1 = pdata->draw->color[0];
		color2 = pdata->draw->color[1];
		if (color1 == color2)
			return (color1);
	}
	if (!opt)
		prc = percent(0, pdata->z_max, current);
	else
		prc = percent(0, pdata->draw->dx, current);
	return (get_gradient(prc, color1, color2));
	//else if (pdata->matrix[*i][*j] < z_alt[1] * 2 / 3)
	//	return (0x00FF0000);
}
/*
int get_color(t_data *pdata, *i)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

//	if (pdata->color[0] == pdata->color[1])
//		return (pdata->color[0]);

	percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}
*/
