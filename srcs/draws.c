#include "../include/fdf.h"

int			draw_lines(t_data *pdata)
{
	int i;
	int j;
	int x1;
	int y1;
	int x2;
	int y2;

	
	i = -1;
	while (++i < pdata->mrows)
	{
		j = 0;
		y1 = (pdata->map_y)[i][j] + W_HEIGHT / 4;
		x1 = (pdata->map_x)[i][j] + W_WIDTH / 4;
		while (j < pdata->mcols - 1)
		{
			y2 = (pdata->map_y)[i][j + 1] + W_HEIGHT / 4;
			x2 = (pdata->map_x)[i][j + 1] + W_WIDTH / 4;
			draw_line(pdata, x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
			j++;
		}
	}
	j = -1;
	while (++j < pdata->mcols)
	{
		i = 0;
		y1 = (pdata->map_y)[i][j] + W_HEIGHT / 4;
		x1 = (pdata->map_x)[i][j] + W_WIDTH / 4;
		while (i < pdata->mrows - 1)
		{
			y2 = (pdata->map_y)[i + 1][j] + W_HEIGHT / 4;
			x2 = (pdata->map_x)[i + 1][j] + W_WIDTH / 4;
			draw_line(pdata, x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
			i++;
		}
	}


	//draw_line(pdata, pdata->map_x[1][1] * TILE_WIDTH + W_WIDTH / 4, pdata->map_y[1][1] *  TILE_HEIGHT + W_HEIGHT / 4, pdata->map_x[9][8] * TILE_WIDTH + W_WIDTH / 4, pdata->map_y[9][8] * TILE_HEIGHT + W_HEIGHT / 4);
	return (0);

}

int			draw_points(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = 0;
		while (j < pdata->mcols)
		{
			put_pixel(pdata, (pdata->map_x)[i][j] + W_WIDTH / 4, (pdata->map_y)[i][j] + W_HEIGHT / 4, 0xFFFFFF);
			j++;
		}
	}
	return (0);
}
