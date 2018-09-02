#include "../include/fdf.h"
#include "../include/get_next_line.h"

//void		fill_pixel(char *img_data, int x, int y, unsigned int color);
/*int deal_key(int key, void *param)
{
	ft_putchar('X');
	//mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF);
	return (0);
}*/
int main(int argc, char **argv)
{
	t_data	data;
	t_data	*pdata;

	if (argc != 2)
		return (specific_error("Usage: ./fdf map.fdf\n"));
	pdata = &data;
	if (retrieve_data(argv[1], pdata))
		return (1);
	printf("value 1 1: %d\n", (pdata->matrix)[0][0]);
	printf("value mrows: %d, value mcols: %d\n", pdata->mrows, pdata->mcols);
	pdata->mlx_ptr = mlx_init();
	pdata->win_ptr = mlx_new_window(pdata->mlx_ptr, 800, 600, "mlx 42");
	pdata->img_ptr = mlx_new_image(pdata->mlx_ptr, 800, 600);
	pdata->img_data = mlx_get_data_addr(pdata->img_ptr, &(pdata->bpp), &(pdata->size_line), &(pdata->endian));
	printf("bpp es: %d\n", pdata->bpp);
	printf("size_line es %d\n", pdata->size_line);
	printf("endian es %d\n", pdata->endian);
	printf("color value: %u\n", mlx_get_color_value(pdata->mlx_ptr, 0xFF0000));
	fill_map(pdata);
	//fill_pixel(pdata, 4 * pdata->bpp / 8, TILE_HEIGHT * pdata->size_line, 0xFFFFFF);
	//fill_pixel(img_data, 4 * bpp / 8, 1 * size_line, 0xFFFFFF);
	mlx_put_image_to_window(pdata->mlx_ptr, pdata->win_ptr, pdata->img_ptr, 0, 0);
	/*x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y1 + (((y2 - y1) * (x - x1))/(x2 - x1)), 0xFFFFFF);
		x++;
	}
	while (angle <= 360.0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1 + radius * cos(angle), y1 + radius * sin(angle), 0xFFFFFF);
		angle = angle + 0.01;
	}
	//mlx_pixel_put (mlx_ptr, win_ptr, 4, 4, 0xFFFFFF);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	*/
	mlx_loop(pdata->mlx_ptr);
	free_matrix(pdata, pdata->mrows);
	return (0);
}
