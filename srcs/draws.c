/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:48 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/28 16:17:16 by gofernan         ###   ########.fr       */
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
		pdata->draw->y1 = (pdata->map_y)[i][j] + pdata->center_y;
		pdata->draw->x1 = (pdata->map_x)[i][j] + pdata->center_x;
		pdata->draw->color[0] = point_color(pdata, pdata->map_col[i][j], 0);
		while (j < pdata->mcols - 1)
		{
			pdata->draw->y2 = (pdata->map_y)[i][j + 1] + pdata->center_y;
			pdata->draw->x2 = (pdata->map_x)[i][j + 1] + pdata->center_x;
			pdata->draw->color[1] = point_color(pdata, pdata->map_col[i][j + 1], 0);
			draw_line(pdata);
			pdata->draw->x1 = pdata->draw->x2;
			pdata->draw->y1 = pdata->draw->y2;
			pdata->draw->color[0] = pdata->draw->color[1];
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
		pdata->draw->y1 = (pdata->map_y)[i][j] + pdata->center_y;
		pdata->draw->x1 = (pdata->map_x)[i][j] + pdata->center_x;
		pdata->draw->color[0] = point_color(pdata, pdata->map_col[i][j], 0);
		while (i < pdata->mrows - 1)
		{
			pdata->draw->y2 = (pdata->map_y)[i + 1][j] + pdata->center_y;
			pdata->draw->x2 = (pdata->map_x)[i + 1][j] + pdata->center_x;
			pdata->draw->color[1] = point_color(pdata, pdata->map_col[i + 1][j], 0);
			draw_line(pdata);
			pdata->draw->x1 = pdata->draw->x2;
			pdata->draw->y1 = pdata->draw->y2;
			pdata->draw->color[0] = pdata->draw->color[1];
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
			put_pixel(pdata, (pdata->map_x)[i][j] + pdata->center_x,
					(pdata->map_y)[i][j] + pdata->center_y, point_color(pdata, pdata->map_col[i][j], 0));
			j++;
		}
	}
}

void		put_pixel(t_data *pdata, int x, int y, unsigned int color)
{
	char		*newaddr;
	int			pixel;

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
	if (pdata->lines)
	{
		draw_xlines(pdata);
		draw_ylines(pdata);
	}
	draw_info(pdata);
	return (0);
}
