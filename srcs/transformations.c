#include "../include/fdf.h"

void		iso(int *x, int *y, int *z)
{
	int temp_x;

	temp_x = *x;
	*x = (*x - *y) * cos(0.523599);
	*y = -*z + (temp_x + *y) * sin(0.523599);
}

void		rotation_x(t_data *pdata, int *x, int *y, int *z)
{
	int temp_y;

	temp_y = *y;
	*y = (temp_y * cos(pdata->rot_radx) + (*z * -sin(pdata->rot_radx)));
	*z = (temp_y * sin(pdata->rot_radx) + (*z * cos(pdata->rot_radx)));
}

void		rotation_y(t_data *pdata, int *x, int *y, int *z)
{
	int temp_x;

	temp_x = *x;
	*x = (temp_x * cos(pdata->rot_rady) + (*z * sin(pdata->rot_rady)));
	*z = (temp_x * -sin(pdata->rot_rady) + (*z * cos(pdata->rot_rady)));
}

void		rotation_z(t_data *pdata, int *x, int *y, int *z)
{
	int temp_x;

	temp_x = *x;
	*x = (*x * cos(pdata->rot_radz) + (*y * sin(pdata->rot_radz)));
	*y = (temp_x * sin(pdata->rot_radz) + (*y * cos(pdata->rot_radz)));
}
void		rotation(t_data *pdata, int *x, int *y, int *z)
{
	if (pdata->rot_x)
	{
		rotation_x(pdata, x, y, z);
		iso(x, y, z);
	}
	if (pdata->rot_y)
	{
		rotation_y(pdata, x, y, z);
		iso(x, y, z);
	}
	if (pdata->rot_z)
	{
		rotation(pdata, x, y, z);
		iso(x, y, z);
	}
}
/*
void		rotation(t_data *pdata, int *x, int *y, int *z)
{
	int temp_x;
	int temp_y;
	int temp_z;

	float new_x;
	float new_y;
	float new_z;

	new_x = *x;
	new_y = *y;
	new_z = *z;

	temp_y = *y;
	temp_x = *x;
	temp_z = *z;
	if (pdata->rot_y)
	{
		new_x = (new_x * cos(pdata->rot_rady) + (new_z * sin(pdata->rot_rady)));
		new_z = (temp_x * -sin(pdata->rot_rady) + (new_z * cos(pdata->rot_rady)));
	}
	if (pdata->rot_x)
	{
		new_y = (new_y * cos(pdata->rot_radx) + (new_z * sin(pdata->rot_radx)));
		new_z = (temp_y * -sin(pdata->rot_radx) + (new_z * cos(pdata->rot_radx)));
	}
	temp_x = new_x;
	if (pdata->rot_z)
	{
		new_x = (new_x * cos(pdata->rot_radz) + (new_y * sin(pdata->rot_radz)));
		new_y = (temp_x * sin(pdata->rot_radz) + (new_y * cos(pdata->rot_radz)));
	}
	*x = new_x;
	*y = new_y;
	*z = new_z;
}
*/
void		scaling(t_data *pdata, int *x, int *y)
{

	//if (pdata->scaling_v > 0)
	//{
		*x = *x * pdata->scaling_v;
		*y = *y * pdata->scaling_v;
	//}
	/*else
	{
		*x = *x * -pdata->scaling_v;
		*y = *y / -pdata->scaling_v;
	}
	*/
}
