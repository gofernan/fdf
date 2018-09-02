#include "../include/fdf.h"

int			parallel_proj(t_data *pdata)
{
	int i;
	int j;
	int x1;
	int y1;
	int	x2;
	int	y2;
	int x;
	int y;

	i = -1;
	x1 = 0;
	y1 = 0;
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			x2 = j * pdata->bpp / 8 * TILE_WIDTH;
			y2 = i * pdata->size_line * TILE_HEIGHT;
			fill_pixel(pdata, x2, y2, 0xFFFFFF);
			x = x1;
			while (x < x2)
			{
				y = y1 + (((y2 - y1) * (x - x1))/(x2 - x1));
				fill_pixel(pdata, x, y, 0xFFFFFF);
				x = x + (pdata->bpp / 8);
			}
			x1 = x2;
			y1 = y2;
		}
	}
	return (0);
}
