#include "../include/fdf.h"
#include "../include/get_next_line.h"
void		init_v(t_data *pdata)
{
	pdata->degrees = 30;
	pdata->mlx_ptr = mlx_init();
	pdata->win_ptr = mlx_new_window(pdata->mlx_ptr, W_WIDTH, W_HEIGHT, "mlx 42");
	pdata->img_ptr = mlx_new_image(pdata->mlx_ptr, W_WIDTH, W_HEIGHT);
	pdata->img_data = mlx_get_data_addr(pdata->img_ptr, &pdata->bpp, &pdata->size_line, &pdata->endian);
	pdata->pixelbytes = pdata->bpp / 8;
	pdata->tlimit = W_WIDTH * W_HEIGHT * pdata->bpp / 8;
	pdata->rlimit = pdata->size_line / pdata->pixelbytes;
}


int			close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			key_press(int keycode, void *param)
{
	if (keycode == 1)
		ft_putchar('A');
	else if (keycode == 53)
		close_window(param);
	return (0);
}
void		information(t_data *pdata)
{
	printf("bpp es: %d\n", pdata->bpp);
	printf("size_line es %d\n", pdata->size_line);
	printf("endian es %d\n", pdata->endian);
	printf("color value: %u\n", mlx_get_color_value(pdata->mlx_ptr, 0xFF0000));
	stored_correctly(pdata);
}

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

	if (argc != 2)
		return (specific_error("Usage: ./fdf map.fdf\n"));
	if (retrieve_data(argv[1], &data))
		return (1);
	printf("value 1 1: %d\n", (data.matrix)[0][0]);
	printf("value mrows: %d, value mcols: %d\n", data.mrows, data.mcols);
	init_v(&data);
	information(&data);
	create_map(&data);
	convert_map(&data);
	fill_map(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	//mlx_key_hook(data.win_ptr, &key_press, &data);
	mlx_hook(data.win_ptr, 2, 0, &key_press, (void *)0);
	mlx_hook(data.win_ptr, 17, 0, &close_window, (void *)0);
	//mlx_loop_hook(data.mlx_ptr, &img_transform, (void *)0);
	mlx_loop(data.mlx_ptr);
	free_matrix(&data, data.mrows);
	return (0);
}
