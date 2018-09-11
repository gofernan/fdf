#include "../include/fdf.h"

int			clear_img(t_data *pdata)
{
	int i;
	int j;
	int pixel;

	/*i = -1;
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			pixel = pdata->map_x[i][j] * pdata->pixelbytes + pdata->map_y[i][j]	* pdata->size_line;
			if (pdata->map_x[i][j] >= 0 && pdata->map_x[i][j] <= pdata->rlimit &&
					pdata->map_y[i][j] >= 0 && pixel <= pdata->tlimit)
				pdata->img_data[pixel] = 0;
		}
	}
	*/
	i = -1;
	while (++i <= pdata->tlimit)
	{
		(pdata->img_data)[i] = 0;
	}
	return (0);
}
