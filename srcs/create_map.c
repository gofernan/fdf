/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:34 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 10:00:46 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			convert_map(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			(pdata->map_x)[i][j] = j * pdata->ytile;
			(pdata->map_y)[i][j] = i * pdata->xtile;
			(pdata->map_z)[i][j] = (pdata->matrix)[i][j] * pdata->ztile;
			if (!pdata->reset)
			{
				if (pdata->rot_x || pdata->rot_y || pdata->rot_z)
					rotation(pdata, &i, &j);
				if (pdata->proj)
					iso(pdata, &i, &j);
				if (pdata->move_x || pdata->move_y)
					move_xy(pdata, &i, &j);
				if (pdata->scaling != 1.0)
					scaling(pdata, &pdata->map_x[i][j], &pdata->map_y[i][j]);
			}
		}
	}
	return (0);
}

int			create_map(t_data *pdata)
{
	int i;

	i = 0;
	if (!(pdata->map_x = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 0, 0);
	if (!(pdata->map_y = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 1, 0);
	if (!(pdata->map_z = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 2, 0);
	while (i < pdata->mrows)
	{
		if (!((pdata->map_x)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 3, i - 1);
		if (!((pdata->map_y)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 4, i - 1);
		if (!((pdata->map_z)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 5, i - 1);
		i++;
	}
	return (0);
}

void		pre_convert_map(t_data *pdata)
{
	if (pdata->rot_y)
		pdata->rot_rady = pdata->rot_y * M_PI / 180;
	if (pdata->rot_x)
		pdata->rot_radx = pdata->rot_x * M_PI / 180;
	if (pdata->rot_z)
		pdata->rot_radz = pdata->rot_z * M_PI / 180;
}
