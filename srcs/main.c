/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:36:11 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/28 16:16:39 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/get_next_line.h"

void			init_start(t_data *pdata)
{
	pdata->rot_x = 0;
	pdata->rot_y = 0;
	pdata->rot_z = 0;
	pdata->xtile = 40;
	pdata->ytile = 40;
	pdata->ztile = 40;
	pdata->scaling = 1.0;
	pdata->lines = 1;
	pdata->move_x = 0;
	pdata->move_y = 0;
	pdata->mouse_x = 0;
	pdata->mouse_y = 0;
	pdata->mouse_press = 0;
}

void			init_v(t_data *pdata)
{
	pdata->mlx_ptr = mlx_init();
	pdata->win_ptr = mlx_new_window(pdata->mlx_ptr, W_WIDTH, W_HEIGHT, "FDF");
	pdata->img_ptr = mlx_new_image(pdata->mlx_ptr, W_WIDTH, W_HEIGHT);
	pdata->img_data = mlx_get_data_addr(pdata->img_ptr, &pdata->bpp,
			&pdata->size_line, &pdata->endian);
	pdata->pixelbytes = pdata->bpp / 8;
	pdata->tlimit = W_WIDTH * W_HEIGHT * pdata->bpp / 8 - 1;
	pdata->rlimit = pdata->size_line / pdata->pixelbytes - 1;
	if (!(pdata->draw = (t_draw *)malloc(sizeof(t_draw))))
	{
		free_matrix(pdata, pdata->mrows);
		exit(EXIT_FAILURE);
	}
	if (W_WIDTH >= 400 && W_HEIGHT >= 140)
		pdata->info = 1;
	else
		pdata->info = 0;
	pdata->action = 0;
	pdata->reset = 0;
	init_start(pdata);
	pdata->z_max = 0;
	pdata->z_min = 0;
	pdata->proj = 1;
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
	create_map(&data);
	map_size(&data);
	convert_map(&data);
	draw_map(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	draw_info(&data);
	mlx_hook(data.win_ptr, 2, 0, &key_press, &data);
	mlx_hook(data.win_ptr, 4, 0, &mouse_press, &data);
	mlx_hook(data.win_ptr, 6, 0, &mouse_move, &data);
	mlx_hook(data.win_ptr, 5, 0, &mouse_release, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop_hook(data.mlx_ptr, &img_transform, &data);
	mlx_loop(data.mlx_ptr);
	free_matrix(&data, data.mrows);
	return (0);
}
