/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:04:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/10/05 18:33:04 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			map_nofit(t_data *pdata)
{
	pdata->center_x = W_WIDTH / 2 - (pdata->xtile *
		(pdata->mcols - 1) + 1) / 2;
	pdata->center_y = W_HEIGHT / 2 - (pdata->ytile *
		(pdata->mrows - 1) + 1) / 2;
	return (0);
}

int			map_exceptions(t_data *pdata)
{
	if (pdata->mrows == 1 && pdata->mcols != 1)
	{
		pdata->center_x = W_WIDTH / 2 - (pdata->xtile *
				(pdata->mcols - 1) + 1) / 2;
		pdata->center_y = W_HEIGHT / 2;
	}
	if (pdata->mcols == 1 && pdata->mrows != 1)
	{
		pdata->center_x = W_WIDTH / 2;
		pdata->center_y = W_HEIGHT / 2 - (pdata->ytile *
				(pdata->mrows - 1) + 1) / 2;
	}
	if (pdata->mcols == 1 && pdata->mrows == 1)
	{
		pdata->center_x = W_WIDTH / 2;
		pdata->center_y = W_HEIGHT / 2;
	}
	return (0);
}

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
		if (pdata->xtile < 3 || pdata->ytile < 3 || pdata->ztile < 3)
			return (1);
		(pdata->xtile)--;
		(pdata->ytile)--;
		(pdata->ztile)--;
	}
	if (apply)
		convert_map(pdata);
	return (0);
}

int			map_size_iso(t_data *pdata, int wlim, int hlim)
{
	int diffx;
	int	diffy;
	int	minx;
	int	miny;

	while ((diffx = ft_abs(big_small(pdata, pdata->map_x, 0)) +
		big_small(pdata, pdata->map_x, 1)) < wlim)
		if (resize_tile(pdata, 1, 1))
			return (1);
	while ((diffy = ft_abs(big_small(pdata, pdata->map_y, 0)) +
		big_small(pdata, pdata->map_y, 1)) < hlim)
		if (resize_tile(pdata, 1, 1))
			return (1);
	while ((diffx = ft_abs(big_small(pdata, pdata->map_x, 0)) +
		big_small(pdata, pdata->map_x, 1)) >= wlim)
		if (resize_tile(pdata, 0, 1))
			return (1);
	while ((diffy = ft_abs(big_small(pdata, pdata->map_y, 0)) +
		big_small(pdata, pdata->map_y, 1)) >= hlim)
		if (resize_tile(pdata, 0, 1))
			return (1);
	diffx = ft_abs(big_small(pdata, pdata->map_x, 0)) +
		big_small(pdata, pdata->map_x, 1);
	diffy = ft_abs(big_small(pdata, pdata->map_y, 0)) +
		big_small(pdata, pdata->map_y, 1);
	minx = big_small(pdata, pdata->map_x, 0);
	miny = big_small(pdata, pdata->map_y, 0);
	pdata->center_x = (W_WIDTH - diffx) / 2 + (minx < 0 ? -minx : minx);
	pdata->center_y = (W_HEIGHT - diffy) / 2 + (miny < 0 ? -miny : miny);
	return (0);
}

int			map_size_normal(t_data *pdata, int wlim, int hlim)
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
	return (0);
}

int			map_size(t_data *pdata)
{
	int wlim;
	int hlim;

	wlim = W_WIDTH - W_WIDTH * 0.10;
	hlim = W_HEIGHT - W_HEIGHT * 0.10;
	if (pdata->proj)
	{
		if (pdata->mrows == 1 && pdata->mcols == 1)
			map_exceptions(pdata);
		else
		{
			convert_map(pdata);
			if (map_size_iso(pdata, wlim, hlim))
				map_nofit(pdata);
		}
	}
	else
	{
		if (pdata->mrows == 1 || pdata->mcols == 1)
			map_exceptions(pdata);
		else
		{
			if (map_size_normal(pdata, wlim, hlim))
				map_nofit(pdata);
		}
	}
	return (0);
}
