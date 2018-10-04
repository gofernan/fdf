/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:04:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/28 16:04:49 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			resize_tile(t_data *pdata, int resize, int apply)
{
	if (resize)
	{
		(pdata->xtile)++;
		(pdata->ytile)++;
		(pdata->ztile)++;
	}
	else
	{
		if (pdata->xtile < 2 || pdata->ytile < 2 || pdata->ztile < 2)
			return (1);
		(pdata->xtile)--;
		(pdata->ytile)--;
		(pdata->ztile)--;
	}
	if (apply)
		convert_map(pdata);
	return (0);
}

int			big_small(t_data *pdata, int **map, int opt)
{
	int i;
	int j;
	int bgosm;

	i = -1;
	bgosm = map[0][0];
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			if (opt)
			{
				if (map[i][j] > bgosm)
					bgosm = map[i][j];
			}
			else
			{
				if (map[i][j] < bgosm)
					bgosm = map[i][j];
			}
		}
	}
	return (bgosm);
}



void		map_size_iso(t_data *pdata, int wlim, int hlim)
{
	int diffx;
	int	diffy;
	int	minx;
	int	miny;

	convert_map(pdata);
	while ((diffx = ft_abs(big_small(pdata, pdata->map_x, 0)) +
		big_small(pdata, pdata->map_x, 1)) < wlim)
		resize_tile(pdata, 1, 1);
	while ((diffy = ft_abs(big_small(pdata, pdata->map_y, 0)) +
		big_small(pdata, pdata->map_y, 1)) < hlim)
		resize_tile(pdata, 1, 1);
	while ((diffx = ft_abs(big_small(pdata, pdata->map_x, 0)) +
		big_small(pdata, pdata->map_x, 1)) >= wlim)
		resize_tile(pdata, 0, 1);
	while ((diffy = ft_abs(big_small(pdata, pdata->map_y, 0)) +
		big_small(pdata, pdata->map_y, 1)) >= hlim)
		resize_tile(pdata, 0, 1);
	diffx = ft_abs(big_small(pdata, pdata->map_x, 0)) +
		big_small(pdata, pdata->map_x, 1);
	diffy = ft_abs(big_small(pdata, pdata->map_y, 0)) +
		big_small(pdata, pdata->map_y, 1);  
	minx = big_small(pdata, pdata->map_x, 0);
	miny = big_small(pdata, pdata->map_y, 0);
	minx = minx < 0 ? -minx : minx;
	miny = miny < 0 ? -miny : miny;
	pdata->center_x = (W_WIDTH - diffx) / 2 + minx;
	pdata->center_y = (W_HEIGHT - diffy) / 2 + miny;
}
/*
int			map_size_normal(t_data *pdata, int wlim, int hlim)
{
	while ((pdata->center_x = (pdata->mcols - 1) * pdata->xtile + 1) < wlim)
		resize_tile(pdata, 1, 0);
	while ((pdata->center_y = (pdata->mrows - 1) * pdata->ytile + 1) < hlim)
		resize_tile(pdata, 1, 0);
	while ((pdata->center_x = (pdata->mcols - 1) * pdata->xtile + 1) > wlim)
		resize_tile(pdata, 0, 0);
	while ((pdata->center_y = (pdata->mrows - 1) * pdata->ytile + 1) > hlim)
		resize_tile(pdata, 0, 0);
	pdata->center_x = (pdata->mcols - 1) * pdata->xtile + 1;
	pdata->center_y = (pdata->mrows - 1) * pdata->ytile + 1;
	pdata->center_x = (W_WIDTH - pdata->center_x) / 2;
	pdata->center_y = (W_HEIGHT - pdata->center_y) / 2;
	return (0);
}
*/

int			map_size(t_data *pdata)
{
	int wlim;
	int hlim;

	// ATENTTION COLUMN 1 BREAK ALL
	wlim = W_WIDTH - W_WIDTH * 0.10;
	hlim = W_HEIGHT - W_HEIGHT * 0.10;
	if (pdata->proj)
		map_size_iso(pdata, wlim, hlim);
	else
	{
		while ((pdata->center_x = (pdata->mcols - 1) * pdata->xtile + 1) < wlim)
			if (resize_tile(pdata, 1, 0))
				return (1);
		while ((pdata->center_y = (pdata->mrows - 1) * pdata->ytile + 1) < hlim)
			if (resize_tile(pdata, 1, 0))
				return (1);
		while ((pdata->center_x = (pdata->mcols - 1) * pdata->xtile + 1) > wlim)
			if (resize_tile(pdata, 0, 0))
				return (1);
		while ((pdata->center_y = (pdata->mrows - 1) * pdata->ytile + 1) > hlim)
			if (resize_tile(pdata, 0, 0))
				return (1);
		pdata->center_x = (pdata->mcols - 1) * pdata->xtile + 1;
		pdata->center_y = (pdata->mrows - 1) * pdata->ytile + 1;
		pdata->center_x = (W_WIDTH - pdata->center_x) / 2;
		pdata->center_y = (W_HEIGHT - pdata->center_y) / 2;
	}
	return (0);
}
