#include "../include/fdf.h"
/*
float			percent(int start, int end, int current)
{
	//float percent;
	//percent = (current - start) / (end - start);
	return (current/end);
}
*/
int			point_color(t_data *pdata, int *i, int *j)
{
	if (pdata->map_col[*i][*j] == pdata->z_max)
		return (0x00FF00);
	//else if (pdata->matrix[*i][*j] < z_alt[1] * 2 / 3)
	//	return (0x00FF0000);
	return (0xFFFFFF);
}
/*
int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_data *pdata, *i)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

	if (pdata->color[0] == pdata->color[1])
		return (pdata->color[0]);

	percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}
*/
