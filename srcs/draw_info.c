#include "../include/fdf.h"

void		draw_info(t_data *pdata)
{
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 0,
			0x00FFFFFF, "MOVE:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 0,
			0x00FFFFFF, "UP/DOWN/LEFT/RIGHT");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 20,
			0x00FFFFFF, "ROTATION:"); 
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 20,
			0x00FFFFFF, "MOUSE/KEYPAD"); 
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 40,
			0x00FFFFFF, "ZOOM IN/OUT:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 40,
			0x00FFFFFF, "+/-");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 60,
			0x00FFFFFF, "CLOSE WINDOW:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 60,
			0x00FFFFFF, "ESC");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 80,
			0x00FFFFFF, "RESTART:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 80,
			0x00FFFFFF, "R");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 100,
			0x00FFFFFF, "SHOW/HIDE INFO:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 100,
			0x00FFFFFF, "I");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 120,
			0x00FFFFFF, "ISO PROJECTION:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 120,
			0x00FFFFFF, "1");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 140,
			0x00FFFFFF, "X ROTATION:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 140,
			0x00FFFFFF, ft_itoa(pdata->rot_x));
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 160,
			0x00FFFFFF, "Y ROTATION:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 160,
			0x00FFFFFF, ft_itoa(pdata->rot_y));
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 180,
			0x00FFFFFF, "Z ROTATION:");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 180,
			0x00FFFFFF, ft_itoa(pdata->rot_z));
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 200,
			0x00FFFFFF, "SIZE X(MOD. 1,2):");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 200,
			0x00FFFFFF, ft_itoa(pdata->xtile));
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 220,
			0x00FFFFFF, "SIZE Y(MOD. 3,4):");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 220,
			0x00FFFFFF, ft_itoa(pdata->ytile));
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 400, 240,
			0x00FFFFFF, "SIZE Z(MOD. 5,6):");
	mlx_string_put(pdata->mlx_ptr, pdata->win_ptr, W_WIDTH - 200, 240,
			0x00FFFFFF, ft_itoa(pdata->ztile));
}
