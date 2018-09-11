#include "../include/fdf.h"

int		draw_map(t_data *pdata)
{
	draw_points(pdata);
	draw_lines(pdata);
	return (0);
}
