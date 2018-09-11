/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:48 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 09:52:05 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			draw_lines(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = 0;
		pdata->draw->y1 = (pdata->map_y)[i][j] + W_HEIGHT / 4;
		pdata->draw->x1 = (pdata->map_x)[i][j] + W_WIDTH / 4;
		while (j < pdata->mcols - 1)
		{
			pdata->draw->y2 = (pdata->map_y)[i][j + 1] + W_HEIGHT / 4;
			pdata->draw->x2 = (pdata->map_x)[i][j + 1] + W_WIDTH / 4;
			draw_line(pdata);
			pdata->draw->x1 = pdata->draw->x2;
			pdata->draw->y1 = pdata->draw->y2;
			j++;
		}
	}
	j = -1;
	while (++j < pdata->mcols)
	{
		i = 0;
		pdata->draw->y1 = (pdata->map_y)[i][j] + W_HEIGHT / 4;
		pdata->draw->x1 = (pdata->map_x)[i][j] + W_WIDTH / 4;
		while (i < pdata->mrows - 1)
		{
			pdata->draw->y2 = (pdata->map_y)[i + 1][j] + W_HEIGHT / 4;
			pdata->draw->x2 = (pdata->map_x)[i + 1][j] + W_WIDTH / 4;
			draw_line(pdata);
			pdata->draw->x1 = pdata->draw->x2;
			pdata->draw->y1 = pdata->draw->y2;
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
			put_pixel(pdata, (pdata->map_x)[i][j] + W_WIDTH / 4, (pdata->map_y)[i][j] + W_HEIGHT / 4, 0x00FFFF);
			j++;
		}
	}
	return (0);
}
