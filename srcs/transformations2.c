#include "../include/fdf.h"

void		iso(t_data *pdata, int *i, int *j)
{
	float temp_x;

	temp_x = pdata->map_x[*i][*j];
	pdata->map_x[*i][*j] = (pdata->map_x[*i][*j] - pdata->map_y[*i][*j]) *
		cos(0.523599);
	pdata->map_y[*i][*j] = -pdata->map_z[*i][*j] +
		(temp_x + pdata->map_y[*i][*j]) * sin(0.523599);
}

void		move_xy(t_data *pdata, int *i, int *j)
{
	if (pdata->move_x)
		(pdata->map_x[*i][*j]) += pdata->move_x;
	if (pdata->move_y)
		(pdata->map_y[*i][*j]) += pdata->move_y;
}
