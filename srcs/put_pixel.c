#include "../include/fdf.h"

void		put_pixel(t_data *pdata, int x, int y, unsigned int color)
{
	char *newaddr;
	int pixel;
	int limit;

	if (x >= 0 && x <= pdata->rlimit && y >= 0)
		pixel = x * pdata->pixelbytes + y * pdata->size_line;
	if (pixel <= pdata->tlimit)
	{
		newaddr = pdata->img_data + pixel;
		*newaddr = (char)(color);
		*(newaddr + 1) = (char)(color >> 8);
		*(newaddr + 2) = (char)(color >> 16);
		*(newaddr + 3) = (char)(color >> 24);
	}
}
