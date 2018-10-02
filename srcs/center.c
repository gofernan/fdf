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

int			resize_tile(t_data *pdata, int resize)
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
	return (0);
}

int			map_size(t_data *pdata)
{
	int w_limit;
	int h_limit;
	int greater;

	w_limit = W_WIDTH - W_WIDTH * 0.10;
	h_limit = W_HEIGHT - W_HEIGHT * 0.10;
	while (pdata->mcols * pdata->xtile < w_limit)
		if (resize_tile(pdata, 1))
			return (1);
	while (pdata->mrows * pdata->ytile < h_limit)
		if (resize_tile(pdata, 1))
			return (1);
	while (pdata->mcols * pdata->xtile > w_limit)
		if (resize_tile(pdata, 0))
			return (1);
	while (pdata->mrows * pdata->ytile > h_limit)
		if (resize_tile(pdata, 0))
			return (1);
	return (0);
}
