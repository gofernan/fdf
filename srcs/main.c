/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:36:11 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 10:06:55 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/get_next_line.h"

void			init_v(t_data *pdata)
{
	pdata->mlx_ptr = mlx_init();
	pdata->win_ptr = mlx_new_window(pdata->mlx_ptr, W_WIDTH, W_HEIGHT, "FDF");
	pdata->img_ptr = mlx_new_image(pdata->mlx_ptr, W_WIDTH, W_HEIGHT);
	pdata->img_data = mlx_get_data_addr(pdata->img_ptr, &pdata->bpp, &pdata->size_line, &pdata->endian);
	pdata->pixelbytes = pdata->bpp / 8;
	pdata->tlimit = W_WIDTH * W_HEIGHT * pdata->bpp / 8 - 1;
	pdata->rlimit = pdata->size_line / pdata->pixelbytes - 1;
	pdata->proj = 1;
	if (!(pdata->draw = (t_draw *)malloc(sizeof(t_draw))))
	{
		free_matrix(pdata, pdata->mrows);
		exit(EXIT_FAILURE);
	}
	pdata->def_data = 0;
	pdata->scaling = 0;
	pdata->rot_x = 0;
	pdata->rot_y = 0;
	pdata->rot_z = 0;
	pdata->rot_vx = 0;
	pdata->rot_vy = 0;
	pdata->rot_vz = 0;
	pdata->degrees = 30;
	pdata->scaling_v = 1;
}

int			close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			key_press(int keycode, t_data *pdata)
{
	pdata->action = 1;
	if (keycode == 1)
		ft_putchar('A');
	else if (keycode == 53)
		close_window(pdata);
	else if (keycode == 69)
	{
		if (pdata->scaling_v > 0.0 && pdata->scaling_v < 32.0)
			pdata->scaling_v *= 2.0;
		pdata->scaling = 1;
	}
	else if (keycode == 78)
	{
		if (pdata->scaling_v >= 0.0625)
		{
			pdata->scaling_v /= 2.0;
			pdata->scaling = 1;
		}
	}
	else if (keycode == 83)
	{
		pdata->rot_vx += 5;
		pdata->rot_radx = pdata->rot_vx * M_PI / 180;
		pdata->rot_x = 1;
	}
	else if (keycode == 85)
	{
		pdata->rot_vy += 5;
		pdata->rot_rady = pdata->rot_vy * M_PI / 180;
		pdata->rot_y = 1;
	}
	else if (keycode == 89)
	{
		pdata->rot_vz += 5;
		pdata->rot_radz = pdata->rot_vz * M_PI / 180;
		pdata->rot_z = 1;
	}
	else
		pdata->action = 0;
	//else if (keycode == 8)
	//	pdata->clear = 1;
	return (0);
}

void	information(t_data *pdata)
{
	printf("bpp es: %d\n", pdata->bpp);
	printf("size_line es %d\n", pdata->size_line);
	printf("endian es %d\n", pdata->endian);
	printf("color value: %u\n", mlx_get_color_value(pdata->mlx_ptr, 0xFF0000));
	stored_correctly(pdata);
}

int		main(int argc, char **argv)
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
	draw_map(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	//mlx_key_hook(data.win_ptr, &key_press, &data);
	mlx_hook(data.win_ptr, 2, 0, &key_press, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop_hook(data.mlx_ptr, &img_transform, &data);
	mlx_loop(data.mlx_ptr);
	free_matrix(&data, data.mrows);
	return (0);
}
