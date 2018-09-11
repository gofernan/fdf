#include "../include/fdf.h"

int			img_transform(t_data *pdata)
{
	if (pdata->action)
	{
		clear_img(pdata);
		//else if (pdata->scaling > 0)
		//	scaling(t_data *pdata);
		convert_map(pdata);
		draw_map(pdata);
		mlx_put_image_to_window(pdata->mlx_ptr, pdata->win_ptr, pdata->img_ptr, 0, 0);
		pdata->action = 0;
	}
	return (0);
}
