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

void		draw_xlines(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = 0;
		pdata->draw->y1 = (pdata->map_y)[i][j] + W_HEIGHT * 0.05;
		pdata->draw->x1 = (pdata->map_x)[i][j] + W_WIDTH * 0.05;
		//pdata->draw->color[0] = point_color(&i, &j);
		while (j < pdata->mcols - 1)
		{
			pdata->draw->y2 = (pdata->map_y)[i][j + 1] + W_HEIGHT * 0.05;
			pdata->draw->x2 = (pdata->map_x)[i][j + 1] + W_WIDTH * 0.05;
			//pdata->draw->color[1] = point_color(&i, &j);
			draw_line(pdata);
			pdata->draw->x1 = pdata->draw->x2;
			pdata->draw->y1 = pdata->draw->y2;
			j++;
		}
	}
}

void		draw_ylines(t_data *pdata)
{
	int i;
	int j;

	j = -1;
	while (++j < pdata->mcols)
	{
		i = 0;
		pdata->draw->y1 = (pdata->map_y)[i][j] + W_HEIGHT * 0.05;
		pdata->draw->x1 = (pdata->map_x)[i][j] + W_WIDTH * 0.05;
		while (i < pdata->mrows - 1)
		{
			pdata->draw->y2 = (pdata->map_y)[i + 1][j] + W_HEIGHT * 0.05;
			pdata->draw->x2 = (pdata->map_x)[i + 1][j] + W_WIDTH * 0.05;
			draw_line(pdata);
			pdata->draw->x1 = pdata->draw->x2;
			pdata->draw->y1 = pdata->draw->y2;
			i++;
		}
	}
}

void		draw_points(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = 0;
		while (j < pdata->mcols)
		{
			put_pixel(pdata, (pdata->map_x)[i][j] + W_WIDTH * 0.05, (pdata->map_y)[i][j] + W_HEIGHT * 0.05, 0x00FFFF);
			j++;
		}
	}
}

void		put_pixel(t_data *pdata, int x, int y, unsigned int color)
{
	char		*newaddr;
	int			pixel;
	int			limit;

	if (x >= 0 && x <= pdata->rlimit && y >= 0)
	{
		pixel = x * pdata->pixelbytes + y * pdata->size_line;
		if (pixel <= pdata->tlimit)
		{
			newaddr = pdata->img_data + pixel;
			*newaddr = (char)(color);
			*(newaddr + 1) = (char)(color >> 8);
			*(newaddr + 2) = (char)(color >> 16);
			*(newaddr + 3) = (char)(color >> 24);
		}
	}
}

int			draw_map(t_data *pdata)
{
	draw_points(pdata);
	draw_xlines(pdata);
	draw_ylines(pdata);
	draw_info(pdata);
	return (0);
}
