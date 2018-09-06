#include "../include/fdf.h"

float		rotation(t_data *pdata, float x, float y, int axis)
{
	float radian;

	radian = pdata->degrees * M_PI / 180;
	if (axis == 1)
		return (x * cos(radian) - y * sin(radian));
	else if (axis == 2)
		return (x * sin(radian) + y * cos(radian));
	return (0.0);
}

void		iso(int *x, int *y, int *z)
{
	int temp_x;

	temp_x = *x;
	*x = (*x - *y) * cos(0.523599);
	*y = -*z + (temp_x + *y) * sin(0.523599);
}
void	scaling(int *x, int *y)
{
	float temp_x;
	float temp_y;

	temp_x = *x;
	temp_y = *y;
	//*x = -1 * *x;
	//*y = 1 * *y;
	// rotation
	//*x = *y;
	//*y = -1 * temp_x;
	*x = (temp_x * cos(0.523599)) + (temp_y * -sin(0.523599));
	*y = (temp_x * sin(0.523599)) + (temp_y * cos(0.523599));
}
