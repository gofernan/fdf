#include "../include/fdf.h"
#include "../include/get_next_line.h"

void		fill_pixel(char *img_data, int x, int y, unsigned int color);
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	ft_putchar('X');
	//mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF);
	return (0);
}
int main(int argc, char **argv)
{
	t_data	data;
	int		x;
	int		x1 = 0;
	int		x2 = 800;
	int		y1 = 0;
	int		y2 = 0;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "mlx 42");
	data.img_ptr = mlx_new_image(data.mlx_ptr, 800, 600);
	data.img_data = mlx_get_data_addr(data.img_ptr, &data.bpp, &data.size_line, &data.endian);
	printf("bpp es: %d\n", data.bpp);
	printf("size_line es %d\n", data.size_line);
	printf("endian es %d\n", data.endian);
	printf("color value: %u\n", mlx_get_color_value(data.mlx_ptr, 0xFF0000));
	//fill_pixel(img_data, 4 * bpp / 8, 0 * size_line, 0xFFFFFF);
	//fill_pixel(img_data, 4 * bpp / 8, 1 * size_line, 0xFFFFFF);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y1 + (((y2 - y1) * (x - x1))/(x2 - x1)), 0xFFFFFF);
		x++;
	}
	/*
	while (angle <= 360.0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1 + radius * cos(angle), y1 + radius * sin(angle), 0xFFFFFF);
		angle = angle + 0.01;
	}*/
	//mlx_pixel_put (mlx_ptr, win_ptr, 4, 4, 0xFFFFFF);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(data.mlx_ptr);
}
